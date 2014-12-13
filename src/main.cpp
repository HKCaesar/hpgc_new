#include "VectorAlgorithm.h"
#include "v2vproj.h"
#include "EfcPartition.h"
#include "vector.metadata.h"
#include "M2sScheduler.h"
#include "port.debug.h"
#include "timer.h"
#include "rpc.h"
#include "hpgc.h"

#include <iostream>
#include <geoalgorithm.format.h>

using namespace hpgc;

int mainTest(int argc, char ** argv)
{
    Init(argc, argv);
    const char * pszSrcFile = "/home/huangtao/hpgc_new/test";
    const char * pszDstFile =
        "PG:dbname=postgis host=localhost port=5432 user=postgres password=postgres";
    const char * pszSrcLayer = "test";
    const char * pszDstLayer = "test";
    auto net = rpc::RPCNetwork::Get();
    char ** pszlist = NULL;
    pszlist = CSLAddString(pszlist, "OVERWRITE=YES");
    auto srs = (OGRSpatialReference *)OSRNewSpatialReference(NULL);
    srs->SetFromUserInput("EPSG:4326");
    if (net->Id() == 0) {
        auto srcds = VectorOpen(pszSrcFile, GA_ReadOnly);
        auto dstds = VectorOpen(pszDstFile, GA_Update);
        auto srclayer = srcds->GetLayerByName(pszSrcLayer);
        auto dstlayer = dstds->CreateLayer(pszDstLayer, srs, wkbPolygon, pszlist);
        CopyLayerDefine(srclayer, dstlayer);
        VectorClose(dstds);
        VectorClose(srcds);
    }
    auto metadata = new VectorMetaData(pszSrcFile, pszSrcLayer, pszDstFile,
                                       pszDstLayer);
    auto partition = new partition::EfcPartition(2);
    auto celler = partition->Partition(metadata);
    if(net->Id() == 0) {
        auto barrel = celler->GetByIndex(1);
        DataMessage * data = DataMessageFromBarral(barrel);
        std::string str = data->SerializeAsString();
        DataMessage data1;
        data1.ParseFromString(str);
        auto barreltest = BarralFromDataMessage(&data1);
        if (barreltest->GetDstDataSource() == data->dstdatasource()) {
            BUG("dst ds OK");
        }
        else {
            BUG("!! dst ds WRONG");
        }
        if (barreltest->GetDstLayer() == data->dstlayer()) {
            BUG("dst layer OK");
        }
        else {
            BUG("!! dst layer WRONG") ;
        }
        if (barreltest->GetSrcDataSource() == data->srcdatasource()) {
            BUG("src ds OK");
        }
        else {
            BUG("!! src datasource WRONG");
        }
        if (barreltest->GetSrcLayer() == data->srclayer()) {
            BUG("src layer OK");
        }
        else {
            BUG("!! src layer WRONG");
        }
        if (barreltest->Id() == data->dataindex()) {
            BUG("id OK");
        }
        else {
            BUG("!!id WRONG");
        }
    }
    auto scheduler = new scheduler::M2sScheduler();
    auto vct = new algorithm::V2vProj(argc, argv);
    task::GeoTask task = std::bind(&algorithm::V2vProj::Compute, vct, rpc::_1);
    auto alg = new algorithm::VectorAlgorithm(task, scheduler, partition,
            metadata);
    alg->Run();
    return 0;
}

int main(int argc, char ** argv){
	Init(argc,argv);
	auto net = rpc::RPCNetwork::Get();
	std::cout << net->Id() << std::endl;

	if (net->Id() == 1)
	{
		std::cout << "node 1" << std::endl;
	}
	else
	{
		std::cout << "node other" << std::endl;
	}
	net->Id();
	net->Id();
	net->Id();
	return 0;
}
