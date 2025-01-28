#include "TetoEngine/base/Attributeable.hpp"


teto::Attributeable::Attributeable()
{

}

teto::Attributeable::~Attributeable()
{

}

bool teto::Attributeable::hasAttribute(std::string const& attributeKey)
{
    return _attributes.count(attributeKey);
}

teto::Attribute& teto::Attributeable::getAttribute(std::string const& attributeKey)
{
    return _attributes.at(attributeKey);
}