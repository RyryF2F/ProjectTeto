#pragma once

#include "TetoEngine/core/Window.hpp"
#include "TetoEngine/core/TextureRegistry.hpp"

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