#pragma once

#include "raylib.h"

namespace teto
{

    /**
     * C++ Wrapper for raylib Texture (Texture2D)
     */
    class Texture
    {
        public:
            Texture(::Texture2D rayTex);
            ~Texture();

            Texture(const Texture&) = delete;
            Texture& operator = (const Texture&) = delete;

            ::Texture2D& get();

        private:
            ::Texture2D _texture = { 0 };
    };

    /**
     * Wrapper for raylib Mesh
     */
    class Mesh
    {
        public:
            Mesh(::Mesh rayMesh);
            ~Mesh();

            Mesh(const Mesh&) = delete;
            Mesh& operator = (const Mesh&) = delete;

            ::Mesh& get();
        private:
            ::Mesh _mesh = { 0 };
    };

}