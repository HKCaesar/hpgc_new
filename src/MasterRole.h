#ifndef MasterRole_h__
#define MasterRole_h__

#include "IRole.h"
#include "IVectorScheduler.h"
#include "rpc.h"
#include "hpgc.h"
#include "Record.h"

#include <queue>
#include <map>

namespace hpgc {
namespace role {

struct TaskState;
struct Taskid;

class MasterRole : public IRole {
public:
    virtual int Action();
    MasterRole(data::VectorCellar * cellar);
    ~MasterRole();

private:
    bool m_masterRunning;
    std::queue<int> m_activeSlaves;
    std::vector<data::Record> m_statistics;
    rpc::RPCNetwork * m_net;
};
}
}
#endif // MasterRole_h__
