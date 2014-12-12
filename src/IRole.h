#ifndef HPGC_ROLE_H_INCLUDE

#define HPGC_ROLE_H_INCLUDE

#include "VectorBarrel.h"

namespace hpgc {
namespace role {

class IRole {
public:
    virtual int Action() = 0;
};

} /// role
} /// hpgc

#endif