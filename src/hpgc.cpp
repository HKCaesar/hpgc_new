#include "hpgc.h"
#include "rpc.h"

namespace hpgc {
void Init(int argc, char ** argv)
{
    rpc::RPCNetwork::Init();
}
}

