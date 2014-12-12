#ifndef V2VAlgorithm_h__
#define V2VAlgorithm_h__

#include "VectorBarrel.h"

using namespace hpgc::data;

namespace hpgc {
	namespace algorithm {
		class IV2VAlgorithm {
		public:
			virtual bool Compute(const VectorBarral * barrel) = 0;
		};
	}
}

#endif // V2VAlgorithm_h__
