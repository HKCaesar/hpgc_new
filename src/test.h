#ifndef cvct2gdal_h__
#define cvct2gdal_h__

#include "IV2VAlgorithm.h"

namespace hpgc {
namespace algorithm {

class Test : public IV2VAlgorithm {
public:
    virtual bool Compute(const data::VectorBarral * barrel);
};
}
}

#endif // cvct2gdal_h__

