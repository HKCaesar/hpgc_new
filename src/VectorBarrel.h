#ifndef HPGCH_VECTOR_BARREL_H_INCLUDE

#define HPGCH_VECTOR_BARREL_H_INCLUDE

#include <list>
#include <string>
#include "rpc.message.pb.h"

namespace hpgc {
namespace data {

class VectorBarral {

public:

    int Id() const;

    std::string GetSrcDataSource() const;

    std::string GetSrcLayer() const;

    std::list<int> GetFeatures() const;

    std::string GetDstDataSource() const;

    std::string GetDstLayer() const;

	std::string Description() const;

	std::string Extension() const;

    VectorBarral(std::string srcds, std::string srclayer, std::list<int> features,
                 std::string dstds, std::string dstlayer, int id,
				 std::string desc,  std::string ext)
        : m_srcDatasource(srcds)
        , m_srcLayer(srclayer)
        , m_features(features)
        , m_dstDatasource(dstds)
        , m_dstLayer(dstlayer)
        , m_id(id)
		, m_description(desc)
		, m_extension(ext){
    };

    VectorBarral() {};


private:
    std::string m_srcDatasource;
    std::string m_srcLayer;
    std::list<int> m_features;
    std::string m_dstDatasource;
    std::string m_dstLayer;
    int m_id;

	std::string m_description;
	std::string m_extension;
	
};

VectorBarral * BarralFromDataMessage(DataMessage * msg);
DataMessage  * DataMessageFromBarral(VectorBarral * barral);

}
}

#endif