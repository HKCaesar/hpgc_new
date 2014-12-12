#ifndef HpgcVectorAlgorithm_h__
#define HpgcVectorAlgorithm_h__

#include <functional>

#include "IV2VAlgorithm.h"
#include "IVectorPartition.h"
#include "IVectorScheduler.h"
#include "hpgc.h"

namespace hpgc {

	

    class IVectorScheduler;
    class HpgcVectorAlgorithm {

    public:
        HpgcVectorAlgorithm(GeoTask alg, IVectorScheduler * she,
                            IVectorPartition * par, VectorMetaData * data);
        void Run();

        IVectorPartition * GetPartition();
        IVectorScheduler * GetScheduler();
        VectorMetaData  *  GetMetaData();
        GeoTask  GetAlgorithm();

    private:
        GeoTask  m_algorithm;
        IVectorPartition * m_partition;
        IVectorScheduler * m_scheduler;
        VectorMetaData * m_metaData;
    };


}

#endif // HpgcVectorAlgorithm_h__
