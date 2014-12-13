#include "SlaveRole.h"
#include "ScopeGuard.h"
#include "port.debug.h"
#include "timer.h"

#define FLAGS_sleep_time 1

namespace hpgc {
namespace role {

int SlaveRole::Action()
{
    DataMessage dRequest;
    while (m_workRunning) {
        timer::Timer idle;
        while (!m_net->TryRead(0, MessageType::WORKER_RUN_TASK, &dRequest)) {
            timer::Sleep(FLAGS_sleep_time);
            if (!m_workRunning) {
                return 0;
            }
        }
        m_taskRunning = true;
        TaskMessage kRequest;
        data::VectorBarral * barrel = data::BarralFromDataMessage(&dRequest);
        ON_SCOPE_EXIT([&]() {delete barrel; });
        kRequest.set_starttime(timer::TimePoint2String(timer::Now()));
        kRequest.set_dataindex(barrel->Id());
        if (m_task(barrel)) {
            kRequest.set_type(TaskType::TASK_OK);
        }
        else {
            kRequest.set_type(TaskType::TASK_WRONG);
        }
        kRequest.set_endtime(timer::TimePoint2String(timer::Now()));
        m_taskRunning = false;
        m_net->Send(0, MessageType::WORKER_TASK_DONE, kRequest);
    }
    return 0;
}

SlaveRole::SlaveRole(task::GeoTask tk)
{
    m_task        = tk;
    m_net		  = rpc::RPCNetwork::Get();
    m_workRunning = true;
    m_taskRunning = false;
    RegisterCallback(MessageType::WORKER_FINALIZE, new EmptyMessage(),
                     new EmptyMessage, &SlaveRole::HandleGameOver, this);
    RegisterWorkerRequest req;
    req.set_id(Id());
    m_net->Send(0, MessageType::REGISTER_WORKER, req);
}

int SlaveRole::Id()
{
    return m_net->Id();
}

void SlaveRole::HandleGameOver(const EmptyMessage & req, EmptyMessage * resp,
                               const rpc::RPCInfo & rpc)
{
    while (m_taskRunning) {
        timer::Sleep(FLAGS_sleep_time);
    }
    m_taskRunning = false;
    m_workRunning = false;
}

SlaveRole::~SlaveRole()
{
    m_workRunning = false;
}

}
}
