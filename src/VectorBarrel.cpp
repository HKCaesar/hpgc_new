#include "VectorBarrel.h"

namespace hpgc {
namespace data {

std::string VectorBarral::GetSrcDataSource() const
{
    return m_srcDatasource;
}

std::string VectorBarral::GetSrcLayer() const
{
    return m_srcLayer;
}

std::list<int> VectorBarral::GetFeatures() const
{
    return m_features;
}

std::string VectorBarral::GetDstDataSource() const
{
    return m_dstDatasource;
}

std::string VectorBarral::GetDstLayer() const
{
    return m_dstLayer;
}

int VectorBarral::Id() const
{
    return m_id;
}

std::string VectorBarral::Description() const
{
	return m_description;
}

std::string VectorBarral::Extension() const
{
	return m_extension;
}


VectorBarral * BarralFromDataMessage(DataMessage * msg)
{
    auto srcds = msg->srcdatasource();
    auto srclayer = msg->srclayer();
    auto dstds = msg->dstdatasource();
    auto dstlayer = msg->dstlayer();
    auto count = msg->features_size();
    auto id = msg->dataindex();
    std::list<int> feats;
    for (int i = 0; i < count; ++i) {
        feats.push_back(msg->features(i));
    }
    return new VectorBarral(srcds, srclayer, feats, dstds, dstlayer, id,msg->description(),msg->extension());
}

DataMessage * DataMessageFromBarral(VectorBarral * barral)
{
    auto dmsg = new DataMessage();
    dmsg->set_srcdatasource(barral->GetSrcDataSource());
    dmsg->set_srclayer(barral->GetSrcLayer());
    dmsg->set_dstdatasource(barral->GetDstDataSource());
    dmsg->set_dstlayer(barral->GetDstLayer());
    dmsg->set_dataindex(barral->Id());
    auto features = barral->GetFeatures();
    std::for_each(features.begin(), features.end(),
    [&](int id) {dmsg->add_features(id); });
	dmsg->set_description(barral->Description());
	dmsg->set_extension(barral->Extension());
    return dmsg;
}

}
}
