#pragma once

#include "window/Window.hpp"
#include "core/Texture/TextureRegistry.hpp"

namespace tetoedit
{
    class EditorWindow : public ::teto::Window
    {
        public:
        EditorWindow();
        ~EditorWindow();

        void preRun() override;
        int onDraw() override;
        int onUpdate() override;
        int postRun() override;


        private:
            teto::KeyedTextureRegistry TexReg;
    };
}