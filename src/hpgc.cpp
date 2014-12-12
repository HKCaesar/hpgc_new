#include "hpgc.h"
#include "rpc.h"
#include "port.debug.h"

namespace hpgc {
    void Init(int argc, char ** argv) {
        rpc::RPCNetwork::Init();
    }
}

