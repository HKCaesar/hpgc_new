#include "HpgcVectorAlgorithm.h"
#include "MasterRole.h"
#include "SlaveRole.h"
#include "port.debug.h"
#include "IVectorScheduler.h"
#include "ITask.h"

namespace hpgc {
namespace algorithm {

HpgcVectorAlgorithm::HpgcVectorAlgorithm(task::GeoTask alg,
        scheduler::IVectorScheduler * she, partition::IVectorPartition * par,
        VectorMetaData * meta)
{
    m_algorithm = alg;
    m_partition = par;
    m_scheduler = she;
    m_metaData = meta;
}

void HpgcVectorAlgorithm::Run()
{
    m_scheduler->Work(m_algorithm, this);
}

partition::IVectorPartition * HpgcVectorAlgorithm::GetPartition()
{
    return m_partition;
}

scheduler::IVectorScheduler * HpgcVectorAlgorithm::GetScheduler()
{
    return m_scheduler;
}

VectorMetaData * HpgcVectorAlgorithm::GetMetaData()
{
    return m_metaData;
}

task::GeoTask HpgcVectorAlgorithm::GetAlgorithm()
{
    return m_algorithm;
}
}
}
