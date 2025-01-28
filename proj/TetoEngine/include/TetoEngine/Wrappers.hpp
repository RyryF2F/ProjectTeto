#pragma once

#include "raylib.h"

/**
 * Custom wrappers for C classes within raylib.
 * Doing this for myself, and for better memory control.
 */
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

    /**
     * Wrapper for raylib Material
     */
    class Material
    {
        public:
            Material(::Material rayMaterial);
            ~Material();

            Material(const Material&) = delete;
            Material& operator = (const Mesh&) = delete;

            ::Material& get();

            private:
                ::Material _material = { 0 };
    };

    /**
     * Wrapper for raylib Model
     */
    class Model
    {
        public:
            Model(::Model rayModel);
            ~Model();

            Model(const Model&) = delete;
            Model& operator = (const Model&) = delete;

            ::Model& get();

            private:
                ::Model _model = { 0 };
    };

}