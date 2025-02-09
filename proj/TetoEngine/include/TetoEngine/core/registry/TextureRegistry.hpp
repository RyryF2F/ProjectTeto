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

        /**
         * For loading raylib textures in
         */
        void load(K key, ::Texture rayTex, bool waitTillReady = false);

        /**
         * For moving already defined Teto textures in, not working currently due to deleted functions related to mem management
         */
        void add(K key, Texture tex) override;
        void unload(K key);
    };

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
        while (!(IsTextureValid(this->registry.at(key).get()))) //yuck
        {

        }
        TraceLog(LOG_INFO, "Texture Loaded");
    }
}

template<typename K>
void teto::TextureRegistry<K>::unload(K key)
{
    this->registry.erase(key);
}

template <typename K>
void teto::TextureRegistry<K>::add(K key, Texture tex)
{
    this->load(key, tex.get(), false); //uh oh
}