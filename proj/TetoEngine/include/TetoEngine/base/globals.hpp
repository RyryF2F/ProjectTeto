#include <variant>
#include <string>

namespace teto
{
    using Attribute = std::variant<int, float, std::string>;
}