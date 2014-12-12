#ifndef M2sScheduler_h__
#define M2sScheduler_h__

#include "IVectorScheduler.h"
#include "HpgcVectorAlgorithm.h"
#include "ITask.h"
#include "hpgc.h"

namespace hpgc {
	namespace scheduler {

		class M2sScheduler : public IVectorScheduler {
		public:
			virtual void Work(task::GeoTask task, algorithm::HpgcVectorAlgorithm * hpgcAlg);
		};

	}
}

#endif // M2sScheduler_h__
