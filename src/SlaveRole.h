#ifndef SlaveRole_h__
#define SlaveRole_h__

#include "IRole.h"
#include "IV2VAlgorithm.h"
#include "vector.metadata.h"
#include "rpc.h"
#include "rpc.message.pb.h"
#include "HpgcVectorAlgorithm.h"
#include "ITask.h"

namespace hpgc {
namespace role {

class SlaveRole : public IRole {
public:
    virtual int Action();
    SlaveRole(task::GeoTask tk);
    virtual ~SlaveRole();
    int Id();
private:
    bool m_workRunning;
    bool m_taskRunning;
    task::GeoTask m_task;
    rpc::RPCNetwork * m_net;

    void HandleGameOver(const EmptyMessage & req, EmptyMessage * resp,
                        const rpc::RPCInfo & rpc);
};

}
}
#endif // SlaveRole_h__
