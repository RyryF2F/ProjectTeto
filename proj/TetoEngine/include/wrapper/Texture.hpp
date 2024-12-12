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
            Texture(Texture2D rayTex) : _texture(rayTex){};
            ~Texture(){};

            Texture(const Texture&) = delete;
            Texture& operator = (const Texture&) = delete;

            Texture2D& get(){ return _texture; };


        private:
            Texture2D _texture = { 0 };
    };
}