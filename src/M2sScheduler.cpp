#include "M2sScheduler.h"
#include "MasterRole.h"
#include "SlaveRole.h"
#include "vector.metadata.h"
#include "ScopeGuard.h"
#include "rpc.h"
#include "port.debug.h"

#include <geoalgorithm.format.h>

namespace hpgc {
namespace scheduler {

void M2sScheduler::Work(task::GeoTask task,
                        algorithm::HpgcVectorAlgorithm * hpgcAlg)
{
    auto net = rpc::RPCNetwork::Get();
    if (net->Id() == 0) {
        auto meta = hpgcAlg->GetMetaData();
        auto partition = hpgcAlg->GetPartition();
        VectorCellar * srcCellar = partition->Partition(meta);
        role::MasterRole node = { srcCellar };
        node.Action();
    }
    else {
        role::SlaveRole node = { task };
        node.Action();
    }
    net->Barrier();
}

}
}


