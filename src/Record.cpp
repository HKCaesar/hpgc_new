#include "Record.h"
namespace hpgc{
	namespace data {
		Record RecordFromTaskMessage(TaskMessage * msg) {
			Record record;
			record.start_time = msg->starttime();
			record.end_time = msg->endtime();
			record.id = msg->dataindex();
			return record;
		}
	}
}
