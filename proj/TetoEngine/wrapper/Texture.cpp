#include "wrapper/Texture.hpp"

teto::Texture::Texture(Texture2D rayTex) : _texture(rayTex)
{

};

teto::Texture::~Texture()
{
    UnloadTexture(_texture);
    //auto garbage
}

Texture2D& teto::Texture::get()
{
    return _texture;
}