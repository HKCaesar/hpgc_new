#ifndef HPGC_INTERFACE_SCHEDULER_H_INCLUDE

#define HPGC_INTERFACE_SCHEDULER_H_INCLUDE

#include "IRole.h"
#include "IV2VAlgorithm.h"
#include "VectorCellar.h"
#include "HpgcVectorAlgorithm.h"
#include "ITask.h"
#include "hpgc.h"

#include <list>

namespace hpgc {

namespace algorithm {
class VectorAlgorithm;
}

namespace scheduler {


class IVectorScheduler {
public:
    virtual void Work(task::GeoTask tk,
                      algorithm::VectorAlgorithm * hpgcAlg) = 0;
};
}
}

#endif
