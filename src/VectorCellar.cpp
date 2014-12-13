#include "VectorCellar.h"
#include <algorithm>

namespace hpgc {
namespace data {

void VectorCellar::AddBarrel(VectorBarral * barrel)
{
    this->m_barrels.push_back(barrel);
}

VectorBarral * VectorCellar::GetByIndex(int index)
{
    return m_barrels[index];
}

bool VectorCellar::IsEmpty()
{
    return this->m_barrels.empty();
}

VectorCellar::~VectorCellar()
{
}

int VectorCellar::size()
{
    return this->m_barrels.size();
}

}
}
