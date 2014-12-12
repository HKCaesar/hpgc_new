#ifndef HpgcVectorAlgorithm_h__
#define HpgcVectorAlgorithm_h__

#include <functional>

#include "IV2VAlgorithm.h"
#include "IVectorPartition.h"
#include "IVectorScheduler.h"
#include "ITask.h"
#include "vector.metadata.h"

namespace hpgc {

namespace scheduler {
class IVectorScheduler;
}

namespace algorithm {

class HpgcVectorAlgorithm {

public:
    HpgcVectorAlgorithm(task::GeoTask alg, scheduler::IVectorScheduler * she,
                        partition::IVectorPartition * par, data::VectorMetaData * dt);
    void Run();

    partition::IVectorPartition * GetPartition();
    scheduler::IVectorScheduler * GetScheduler();
    data::VectorMetaData  *  GetMetaData();
    task::GeoTask  GetAlgorithm();

private:
    task::GeoTask  m_algorithm;
    partition::IVectorPartition * m_partition;
    scheduler::IVectorScheduler * m_scheduler;
    data::VectorMetaData * m_metaData;
};
}
}

#endif // HpgcVectorAlgorithm_h__
