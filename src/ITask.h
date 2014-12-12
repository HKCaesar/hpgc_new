#ifndef ITASK_H__

#define ITASK_H__

#include "VectorBarrel.h"
#include <functional>

namespace hpgc
{
	namespace task {
		typedef std::function<bool(const VectorBarral * data)> GeoTask;
	}
}
#endif