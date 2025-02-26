#pragma once

#include "raylib.h"
#include "TetoEngine/Wrappers.hpp"
#include "TetoEngine/base/Tickable.hpp"

namespace teto
{
    class Frame
    {
        public:
            Frame();
            Frame(Vector2 pos, Vector2 size);

            void setPos(Vector2 const& pos);
            void setSize(Vector2 const& size);
            
        private:
            Vector2 _pos;
            Vector2 _size;
    };

    class RenderFrame : public Frame, public Tickable
    {
        public:
            RenderFrame();
            RenderFrame(Vector2 pos, Vector2 size);

            void onTick() override;

        private:
            Camera _camera;

    };
}