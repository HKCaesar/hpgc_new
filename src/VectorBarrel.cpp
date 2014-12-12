#include "VectorBarrel.h"

namespace hpgc{
	namespace data {

		std::string VectorBarral::GetSrcDataSource() const{
			return m_srcDatasource;
		}

		std::string VectorBarral::GetSrcLayer() const {
			return m_srcLayer;
		}

		std::list<int> VectorBarral::GetFeatures() const {
			return m_features;
		}

		std::string VectorBarral::GetDstDataSource() const {
			return m_dstDatasource;
		}

		std::string VectorBarral::GetDstLayer() const {
			return m_dstLayer;
		}

		int VectorBarral::Id() const {
			return m_id;
		}


	}
}
