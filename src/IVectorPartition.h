#ifndef VectorPartition_h__
#define VectorPartition_h__

#include "VectorCellar.h"
#include "vector.metadata.h"

namespace hpgc {
	namespace partition {
		class IVectorPartition {
		public:
			virtual VectorCellar * Partition(VectorMetaData * meta) = 0;

		};
	}
}
#endif // VectorPartition_h__
