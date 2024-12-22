#include "core/Texture/TextureRegistry.hpp"

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