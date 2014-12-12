#include "hpgc.h"
#include "rpc.h"
#include "port.debug.h"

namespace hpgc {
    void Init(int argc, char ** argv) {
        rpc::RPCNetwork::Init();
    }

    VectorBarral * BarralFromDataMessage(DataMessage * msg) {
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
        return new VectorBarral(srcds, srclayer, feats, dstds, dstlayer,id);
    }

    DataMessage * DataMessageFromBarral(VectorBarral * barral) {
        auto dmsg = new DataMessage();
        dmsg->set_srcdatasource(barral->GetSrcDataSource());
        dmsg->set_srclayer(barral->GetSrcLayer());
        dmsg->set_dstdatasource(barral->GetDstDataSource());
        dmsg->set_dstlayer(barral->GetDstLayer());
	dmsg->set_dataindex(barral->Id());
	auto features = barral->GetFeatures();
        std::for_each(features.begin(),features.end(), 
			[&](int id) {dmsg->add_features(id); } );

        return dmsg;
    }

    Record RecordFromTaskMessage(TaskMessage * msg) {
        Record record;
        record.start_time = msg->starttime();
        record.end_time = msg->endtime();
        record.id = msg->dataindex();
        return record;
    }


}

