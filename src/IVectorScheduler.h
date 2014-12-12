#ifndef HPGC_INTERFACE_SCHEDULER_H_INCLUDE

#define HPGC_INTERFACE_SCHEDULER_H_INCLUDE

#include "IRole.h"
#include "IV2VAlgorithm.h"
#include "VectorCellar.h"
#include "HpgcVectorAlgorithm.h"
#include "hpgc.h"

#include <list>

namespace hpgc {

    class HpgcVectorAlgorithm;
    class IVectorScheduler {
    public:
        virtual void Work(GeoTask task, HpgcVectorAlgorithm * hpgcAlg) = 0;
    };

}

#endif
