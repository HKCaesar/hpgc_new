#ifndef M2sScheduler_h__
#define M2sScheduler_h__

#include "IVectorScheduler.h"
#include "hpgc.h"

namespace hpgc {

    class M2sScheduler: public IVectorScheduler {
    public:
        virtual void Work(GeoTask task, HpgcVectorAlgorithm * hpgcAlg);
    };

}

#endif // M2sScheduler_h__
