#pragma once

#include "raylib.h"

namespace teto
{
    class Mesh
    {
        public:
            Mesh(::Mesh rayMesh) : _mesh(rayMesh){};
            ~Mesh(){};

            Mesh(const Mesh&) = delete;
            Mesh& operator = (const Mesh&) = delete;

            ::Mesh& get() { return _mesh; }
        private:
            ::Mesh _mesh = { 0 };
    };
}