#include "M2sScheduler.h"
#include "MasterRole.h"
#include "SlaveRole.h"
#include "vector.metadata.h"
#include "ScopeGuard.h"
#include "rpc.h"
#include "port.debug.h"

#include <geoalgorithm.format.h>

void hpgc::M2sScheduler::Work(GeoTask task,
                              HpgcVectorAlgorithm * hpgcAlg) {

    auto net = RPCNetwork::Get();
    if ( net->Id() == 0) {
        auto meta = hpgcAlg->GetMetaData();
        auto partition = hpgcAlg->GetPartition();
        VectorCellar * srcCellar = partition->Partition(meta);

		MasterRole node = { srcCellar };
		node.Action();
    }
    else {
		SlaveRole node = { task };
		node.Action();
    }

    net->Barrier();
}



