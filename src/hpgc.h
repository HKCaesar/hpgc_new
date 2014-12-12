#ifndef common_h__
#define common_h__

#include "rpc.message.pb.h"
#include "VectorBarrel.h"
#include <functional>
#include <string>

namespace hpgc {

	using namespace std;
	using namespace data;

    void Init(int argc, char ** argv);

    struct Record {
        string start_time;
        string end_time;
        int slave;
        int id;

    };

    VectorBarral * BarralFromDataMessage(DataMessage * msg);
    DataMessage  * DataMessageFromBarral(VectorBarral * barral);

    Record  RecordFromTaskMessage(TaskMessage * msg);
}
#endif // common_h__
