#ifndef RECORD_H__
#define RECORD_H__
#include <string>

#include "rpc.message.pb.h"

namespace hpgc {
namespace data {

struct Record {
    std::string start_time;
    std::string end_time;
    int			slave;
    int			id;

};

Record  RecordFromTaskMessage(TaskMessage * msg);
}
}

#endif // !RECORD_H__
