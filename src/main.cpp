#include "VectorAlgorithm.h"
#include "v2vproj.h"
#include "EfcPartition.h"
#include "vector.metadata.h"
#include "M2sScheduler.h"
#include "port.debug.h"
#include "timer.h"
#include "rpc.h"
#include "hpgc.h"
#include "MasterRole.h"
#include "SlaveRole.h"

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
    auto pt = new partition::EfcPartition(2);
    auto celler = pt->Partition(metadata);
    if(net->Id() == 0) {
        auto barrel = celler->GetByIndex(1);
        DataMessage * dt = DataMessageFromBarral(barrel);
        std::string str = dt->SerializeAsString();
        DataMessage data1;
        data1.ParseFromString(str);
        auto barreltest = BarralFromDataMessage(&data1);
        if (barreltest->GetDstDataSource() == dt->dstdatasource()) {
            BUG("dst ds OK");
        }
        else {
            BUG("!! dst ds WRONG");
        }
        if (barreltest->GetDstLayer() == dt->dstlayer()) {
            BUG("dst layer OK");
        }
        else {
            BUG("!! dst layer WRONG") ;
        }
        if (barreltest->GetSrcDataSource() == dt->srcdatasource()) {
            BUG("src ds OK");
        }
        else {
            BUG("!! src datasource WRONG");
        }
        if (barreltest->GetSrcLayer() == dt->srclayer()) {
            BUG("src layer OK");
        }
        else {
            BUG("!! src layer WRONG");
        }
        if (barreltest->Id() == dt->dataindex()) {
            BUG("id OK");
        }
        else {
            BUG("!!id WRONG");
        }
    }
    auto sr = new scheduler::M2sScheduler();
    auto vct = new algorithm::V2vProj(argc, argv);
    task::GeoTask task = std::bind(&algorithm::V2vProj::Compute, vct, rpc::_1);
    auto alg = new algorithm::VectorAlgorithm(task, sr, pt, metadata);
    alg->Run();
    return 0;
}

namespace hpgc {
    namespace simple {
        class SimpleMaster : public role::MasterRole
        {
		public:
			SimpleMaster(data::VectorCellar * cellar):MasterRole(cellar){}
			~SimpleMaster()
			{

			}

			int Action(){ return 1; }
        };

        class SimpleSlave : public role::SlaveRole
        {
		public:
			SimpleSlave(task::GeoTask tk) :SlaveRole(tk){}
			~SimpleSlave()
			{

			}

			int Action(){ return 1; };

        };

		class SimpleScheduler : public scheduler::IVectorScheduler
		{
		public:
			SimpleScheduler();
			~SimpleScheduler();

			void Work(task::GeoTask tk, algorithm::VectorAlgorithm * hpgcAlg);

		private:

		};

		SimpleScheduler::SimpleScheduler()
		{
		}

		SimpleScheduler::~SimpleScheduler()
		{
		}

		void SimpleScheduler::Work(task::GeoTask tk, algorithm::VectorAlgorithm * hpgcAlg)
		{
			auto net = rpc::RPCNetwork::Get();
			if (net->Id() == 0) {
				auto meta = hpgcAlg->GetMetaData();
				auto partition = hpgcAlg->GetPartition();
				auto srcCellar = partition->Partition(meta);
				SimpleMaster node = { srcCellar };
				node.Action();
			}
			else {
				SimpleSlave node = {nullptr};
				node.Action();
			}
			net->Barrier();
		}

        class SimplePartition : public partition::IVectorPartition
        {
		public:
			SimplePartition(){};
			data::VectorCellar * Partition(data::VectorMetaData * meta){
				return nullptr;
			};

        };

		class SimpleAlgorithm : public algorithm::VectorAlgorithm{
		public:
			SimpleAlgorithm(scheduler::IVectorScheduler * sr
				, partition::IVectorPartition * pt
				, data::VectorMetaData * mt
				) :VectorAlgorithm(nullptr, sr, pt, mt){}
			void Run(){
				auto sr = this->GetScheduler();
				sr->Work(nullptr, this);
			}

		};

		class MacroAlgorithm :public algorithm::VectorAlgorithm 
		{
		public:
			MacroAlgorithm();
			~MacroAlgorithm();
			void Run();
			void Add(algorithm::VectorAlgorithm * alg);


		private:
			std::list<algorithm::VectorAlgorithm *> m_algs;

		};

		MacroAlgorithm::MacroAlgorithm() :VectorAlgorithm(nullptr,nullptr,nullptr,nullptr)
		{
		}

		MacroAlgorithm::~MacroAlgorithm()
		{
		}

		void MacroAlgorithm::Run()
		{
			std::for_each(begin(m_algs), end(m_algs), [](VectorAlgorithm * i){i->Run(); });
		}

		void MacroAlgorithm::Add(algorithm::VectorAlgorithm * alg)
		{
			m_algs.push_back(alg);
		}

    }
}


int main(int argc, char ** argv){
    Init(argc,argv);
	auto emptyMetaData = VectorMetaData::Empty();
	auto pt = new simple::SimplePartition();
	auto sr = new simple::SimpleScheduler();
	auto al = new simple::SimpleAlgorithm(sr, pt,emptyMetaData);
	al->Run();
	return 0;
}
