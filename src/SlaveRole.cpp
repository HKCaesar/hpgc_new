#include "SlaveRole.h"
#include "port.debug.h"
#include "timer.h"
#include "hpgc.h"
#include "ScopeGuard.h"
#include "port.debug.h"

#define FLAGS_sleep_time 1

namespace hpgc {
	namespace role {
		int SlaveRole::Action() {
			DataMessage dRequest;
			while (m_workRunning) {
				Timer idle;
				while (!m_net->TryRead(0, WORKER_RUN_TASK, &dRequest)) {
					Sleep(FLAGS_sleep_time);
					if (!m_workRunning) {
						return 0;
					}
				}
				m_taskRunning = true;
				TaskMessage kRequest;
				VectorBarral * barrel = BarralFromDataMessage(&dRequest);
				ON_SCOPE_EXIT([&]() {delete barrel; });
				kRequest.set_starttime(TimePoint2String(Now()));
				kRequest.set_dataindex(barrel->Id());
				if (m_alg(barrel)) {
					kRequest.set_type(TASK_OK);
				}
				else {
					kRequest.set_type(TASK_WRONG);
				}
				kRequest.set_endtime(TimePoint2String(Now()));
				m_taskRunning = false;
				m_net->Send(0, WORKER_TASK_DONE, kRequest);
			}

			return 0;
		}

		SlaveRole::SlaveRole(task::GeoTask task) {
			m_alg = task;
			m_net = rpc::RPCNetwork::Get();
			m_workRunning = true;
			m_taskRunning = false;
			RegisterCallback(WORKER_FINALIZE, new EmptyMessage(),
				new EmptyMessage, &SlaveRole::HandleGameOver, this);

			RegisterWorkerRequest req;
			req.set_id(Id());
			m_net->Send(0, REGISTER_WORKER, req);
		}

		int SlaveRole::Id() {
			return m_net->Id();
		}

		void SlaveRole::HandleGameOver(const EmptyMessage & req, EmptyMessage * resp,
			const rpc::RPCInfo & rpc) {
			while (m_taskRunning) {
				Sleep(FLAGS_sleep_time);
			}
			m_taskRunning = false;
			m_workRunning = false;
		}

		SlaveRole::~SlaveRole() {
			m_workRunning = false;
		}
	}
}
