#ifndef V2VAlgorithm_h__
#define V2VAlgorithm_h__

#include "VectorBarrel.h"

namespace hpgc {
namespace algorithm {
class IV2VAlgorithm {

public:
    virtual bool Compute(const data::VectorBarral * barrel) = 0;
};

}
}

#endif // V2VAlgorithm_h__
