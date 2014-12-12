#ifndef M2sScheduler_h__
#define M2sScheduler_h__

#include "IVectorScheduler.h"
#include "HpgcVectorAlgorithm.h"
#include "ITask.h"

namespace hpgc {
namespace scheduler {

class M2sScheduler : public IVectorScheduler {
public:
    virtual void Work(task::GeoTask tk, algorithm::HpgcVectorAlgorithm * hpgcAlg);
};

}
}

#endif // M2sScheduler_h__
