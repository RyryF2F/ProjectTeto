#pragma once

#include "TetoEngine/base/Drawable.hpp"
#include "TetoEngine/Wrappers.hpp"
#include "raylib.h"
#include <string>

namespace teto
{
    class Frame : public Drawable
    {
        public:
            Frame();
            Frame(Vector2 pos, Vector2 size);
            Frame(Vector2 pos, Vector2 size, teto::Texture* background);

            void setPos(Vector2 const& pos);
            void setSize(Vector2 const& size);
            void setBackground(teto::Texture* background);

            void draw() override;

        private:
            Vector2 _pos;
            Vector2 _size;
            teto::Texture* _background;
    };

    class TextFrame : public Frame
    {
        public:
            using Frame::Frame;
            TextFrame(Vector2 pos, Vector2 size, std::string const& text);

            void setText(std::string const& text);

            void draw() override;
        private:
            std::string _text;
    };
}