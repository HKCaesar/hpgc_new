#include "HpgcVectorAlgorithm.h"
#include "MasterRole.h"
#include "SlaveRole.h"
#include "port.debug.h"
#include "IVectorScheduler.h"

namespace hpgc {
	namespace algorithm {

		HpgcVectorAlgorithm::HpgcVectorAlgorithm(GeoTask alg,
			scheduler::IVectorScheduler * she, IVectorPartition * par, VectorMetaData * meta) {
			m_algorithm = alg;
			m_partition = par;
			m_scheduler = she;
			m_metaData = meta;
		}

		void HpgcVectorAlgorithm::Run() {
			m_scheduler->Work(m_algorithm, this);
		}

		IVectorPartition * HpgcVectorAlgorithm::GetPartition() {
			return m_partition;
		}

		scheduler::IVectorScheduler * HpgcVectorAlgorithm::GetScheduler() {
			return m_scheduler;
		}

		VectorMetaData * HpgcVectorAlgorithm::GetMetaData() {
			return m_metaData;
		}

		GeoTask HpgcVectorAlgorithm::GetAlgorithm() {
			return m_algorithm;
		}
	}
}
