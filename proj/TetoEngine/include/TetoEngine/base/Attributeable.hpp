#pragma once
#include "TetoEngine/base/globals.hpp"
#include <string>
#include <unordered_map>

/**
 * In this game engine, attributes cant be removed. e.g. like a property
 */

namespace teto
{
    class Attributeable
    {
        public:
            Attributeable();
            ~Attributeable();

            bool hasAttribute(std::string const& attributeKey);
            Attribute& getAttribute(std::string const& attributeKey);

        private:
            std::unordered_map<std::string, Attribute> _attributes;
    };
}