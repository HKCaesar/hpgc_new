#include "VectorAlgorithm.h"
#include "MasterRole.h"
#include "SlaveRole.h"
#include "port.debug.h"
#include "IVectorScheduler.h"
#include "ITask.h"

namespace hpgc {
namespace algorithm {

VectorAlgorithm::VectorAlgorithm(task::GeoTask                 tk
                                ,scheduler::IVectorScheduler * sr
                                ,partition::IVectorPartition * pt
                                ,data::VectorMetaData        * mt)
{
    m_task      = tk;
    m_partition = pt;
    m_scheduler = sr;
    m_metaData  = mt;
}

void VectorAlgorithm::Run()
{
    m_scheduler->Work(m_task, this);
}

partition::IVectorPartition * VectorAlgorithm::GetPartition()
{
    return m_partition;
}

scheduler::IVectorScheduler * VectorAlgorithm::GetScheduler()
{
    return m_scheduler;
}

data::VectorMetaData * VectorAlgorithm::GetMetaData()
{
    return m_metaData;
}

task::GeoTask VectorAlgorithm::GetAlgorithm()
{
    return m_task;
}

}
}
