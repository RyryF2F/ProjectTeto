#include "TetoEngine/Wrappers.hpp"

/**
 * TEXTURE
 */
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

/**
 * MESH
 */
teto::Mesh::Mesh(::Mesh rayMesh) : _mesh(rayMesh)
{

};

teto::Mesh::~Mesh()
{
    UnloadMesh(_mesh);
    //auto garbage
}

::Mesh& teto::Mesh::get()
{
    return _mesh;
}