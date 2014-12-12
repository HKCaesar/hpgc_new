#ifndef P2pScheduler_h__
#define P2pScheduler_h__

#include "IVectorScheduler.h"
#include "IRole.h"

namespace hpgc {
namespace scheduler {
using namespace role;

class P2pScheduler : public IVectorScheduler {
public:
    virtual void Work(data::VectorCellar * dt, std::list<IRole> roles,
                      algorithm::IV2VAlgorithm * compute);
    P2pScheduler(data::VectorCellar * dt, std::list<IRole> role,
                 algorithm::IV2VAlgorithm * alg);

private:
    data::VectorCellar * m_celler;
    std::list<IRole> m_roles;
    algorithm::IV2VAlgorithm * m_algorithm;
};

}
}
#endif // P2pScheduler_h__
