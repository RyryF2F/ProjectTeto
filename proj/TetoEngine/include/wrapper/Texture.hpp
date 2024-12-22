/**
 * C++ Wrapper for raylib Texture (Texture2D)
 */

#pragma once
#include "raylib.h"

namespace teto
{
    class Texture
    {
        public:
            Texture(Texture2D rayTex);
            ~Texture();

            Texture(const Texture&) = delete;
            Texture& operator = (const Texture&) = delete;

            Texture2D& get();


        private:
            Texture2D _texture = { 0 };
    };
}