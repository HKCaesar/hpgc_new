#include "HpgcVectorAlgorithm.h"
#include "MasterRole.h"
#include "SlaveRole.h"
#include "port.debug.h"

hpgc::HpgcVectorAlgorithm::HpgcVectorAlgorithm(GeoTask alg,
        IVectorScheduler * she, IVectorPartition * par, VectorMetaData * meta) {
    m_algorithm = alg;
    m_partition = par;
    m_scheduler = she;
    m_metaData = meta;
}

void hpgc::HpgcVectorAlgorithm::Run() {
    m_scheduler->Work(m_algorithm, this);
}

hpgc::IVectorPartition * hpgc::HpgcVectorAlgorithm::GetPartition() {
    return m_partition;
}

hpgc::IVectorScheduler * hpgc::HpgcVectorAlgorithm::GetScheduler() {
    return m_scheduler;
}

hpgc::VectorMetaData * hpgc::HpgcVectorAlgorithm::GetMetaData() {
    return m_metaData;
}

hpgc::GeoTask hpgc::HpgcVectorAlgorithm::GetAlgorithm() {
    return m_algorithm;
}
