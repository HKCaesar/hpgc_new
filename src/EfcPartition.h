#ifndef CvctPartition_h__
#define CvctPartition_h__

#include "IVectorPartition.h"

using namespace hpgc::data;

namespace hpgc {
	namespace partition {
		class EfcPartition : public IVectorPartition {
		public:
			virtual VectorCellar * Partition(VectorMetaData * data);
			EfcPartition(int index);

		private:
			int m_efc;
		};
	}
}
#endif // CvctPartition_h__
