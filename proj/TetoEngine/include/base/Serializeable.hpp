/**
 * base for serialization, essentially meaning that any class derived has instructions for saving.
 */

namespace teto
{
    class Serializable
    {
        public:
            virtual void serialize() = 0;
            virtual void deserialize() = 0;
    };
}