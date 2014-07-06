#include "VectorBarrel.h"


std::string hpgc::VectorBarral::GetSrcDataSource() const{
    return m_srcDatasource;
}

std::string hpgc::VectorBarral::GetSrcLayer() const {
    return m_srcLayer;
}

std::list<int> hpgc::VectorBarral::GetFeatures() const {
    return m_features;
}

std::string hpgc::VectorBarral::GetDstDataSource() const {
    return m_dstDatasource;
}

std::string hpgc::VectorBarral::GetDstLayer() const {
    return m_dstLayer;
}

int hpgc::VectorBarral::Id() const {
	return m_id;
}



