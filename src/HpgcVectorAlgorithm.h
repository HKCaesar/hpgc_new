#ifndef HpgcVectorAlgorithm_h__
#define HpgcVectorAlgorithm_h__

#include <functional>

#include "IV2VAlgorithm.h"
#include "IVectorPartition.h"
#include "IVectorScheduler.h"
#include "hpgc.h"

namespace hpgc {

	namespace scheduler {
		class IVectorScheduler;
	}

	namespace algorithm {

		class HpgcVectorAlgorithm {

		public:
			HpgcVectorAlgorithm(GeoTask alg, scheduler::IVectorScheduler * she,
				IVectorPartition * par, VectorMetaData * data);
			void Run();

			IVectorPartition * GetPartition();
			scheduler::IVectorScheduler * GetScheduler();
			VectorMetaData  *  GetMetaData();
			GeoTask  GetAlgorithm();

		private:
			GeoTask  m_algorithm;
			IVectorPartition * m_partition;
			scheduler::IVectorScheduler * m_scheduler;
			VectorMetaData * m_metaData;
		};
	}
}

#endif // HpgcVectorAlgorithm_h__
