#pragma once


#include "../../base/Registry.hpp"
#include "../../wrapper/Texture.hpp"

namespace teto
{

    template <typename K>
    class TextureRegistry : public Registry<K, Texture>
    {
        public:

        TextureRegistry();
        ~TextureRegistry();

        void clear() override;

        void load(K key, ::Texture rayTex, bool waitTillReady = false);

        void unload(K ind);
    };

    typedef TextureRegistry<int> IndexedTextureRegistry;
    typedef TextureRegistry<std::string> KeyedTextureRegistry;
}
