#ifndef SlaveRole_h__
#define SlaveRole_h__

#include "IRole.h"
#include "IV2VAlgorithm.h"
#include "vector.metadata.h"
#include "rpc.h"
#include "rpc.message.pb.h"
#include "HpgcVectorAlgorithm.h"

namespace hpgc {
    class SlaveRole : public IRole {
    public:
        virtual int Action();
        SlaveRole(GeoTask task);
        ~SlaveRole();
        int Id();
    private:
        bool m_workRunning;
        bool m_taskRunning;
        GeoTask m_alg;
        rpc::RPCNetwork * m_net;

        void HandleGameOver(const EmptyMessage & req, EmptyMessage * resp ,
                            const rpc::RPCInfo & rpc );
    };
}
#endif // SlaveRole_h__
