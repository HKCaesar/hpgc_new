#include "vector.metadata.h"

namespace hpgc {
namespace data {


VectorMetaData::~VectorMetaData()
{
}

VectorMetaData::VectorMetaData(const char * srcds, const char * srclayer,
                               const char * dstds, const char * dstlayer)
{
    m_src = new MetaData(srcds, srclayer);
    m_dst = new MetaData(dstds, dstlayer);
}


MetaData * VectorMetaData::GetSrcMetaData()
{
    return m_src;
}

MetaData * VectorMetaData::GetDstMetaData()
{
    return m_dst;
}

VectorMetaData * VectorMetaData::Empty()
{
	return new VectorMetaData(nullptr, nullptr, nullptr, nullptr);
}

const char * MetaData::GetDataSourceName()
{
    return m_dataSource;
}

MetaData::MetaData(const char * ds, const char * layer)
    : m_dataSource(ds)
    , m_layer(layer)
{
}

const char * MetaData::GetLayerName()
{
    return m_layer;
}

}
}
