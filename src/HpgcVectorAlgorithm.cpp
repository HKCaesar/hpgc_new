#include "HpgcVectorAlgorithm.h"
#include "MasterRole.h"
#include "SlaveRole.h"
#include "port.debug.h"
#include "IVectorScheduler.h"
#include "ITask.h"

namespace hpgc {
namespace algorithm {

HpgcVectorAlgorithm::HpgcVectorAlgorithm(task::GeoTask tk
                                        ,scheduler::IVectorScheduler * sr
                                        ,partition::IVectorPartition * pt
                                        ,data::VectorMetaData * mt)
{
    m_task      = tk;
    m_partition = pt;
    m_scheduler = sr;
    m_metaData  = mt;
}

void HpgcVectorAlgorithm::Run()
{
    m_scheduler->Work(m_task, this);
}

partition::IVectorPartition * HpgcVectorAlgorithm::GetPartition()
{
    return m_partition;
}

scheduler::IVectorScheduler * HpgcVectorAlgorithm::GetScheduler()
{
    return m_scheduler;
}

data::VectorMetaData * HpgcVectorAlgorithm::GetMetaData()
{
    return m_metaData;
}

task::GeoTask HpgcVectorAlgorithm::GetAlgorithm()
{
    return m_task;
}

}
}
