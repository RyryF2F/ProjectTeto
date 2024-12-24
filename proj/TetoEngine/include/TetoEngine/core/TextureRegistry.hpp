#pragma once

#include "TetoEngine/base/Registry.hpp"
#include "TetoEngine/Wrappers.hpp"
#include <string>

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
        void add(K key, Texture val) override {};
        void unload(K ind);
    };

    // typedef TextureRegistry<int> IndexedTextureRegistry;
    // typedef TextureRegistry<std::string> KeyedTextureRegistry;

    using IndexedTextureRegistry = TextureRegistry<int>;
    using KeyedTextureRegistry = TextureRegistry<std::string>;

}

template <typename K>
teto::TextureRegistry<K>::TextureRegistry()
{

}

template <typename K>
teto::TextureRegistry<K>::~TextureRegistry()
{
    clear();
}

template <typename K>
void teto::TextureRegistry<K>::clear()
{
    this->registry.clear();
}

template <typename K>
void teto::TextureRegistry<K>::load(K key, ::Texture rayTex, bool waitTillReady)
{
    this->registry.emplace(std::make_pair(key, rayTex));

    if (waitTillReady)
    {
        TraceLog(LOG_INFO, "Waiting for texture load validation");
        while (!(IsTextureValid(this->registry.at(key).get())))
        {

        }
        TraceLog(LOG_INFO, "Texture Loaded");
    }
}