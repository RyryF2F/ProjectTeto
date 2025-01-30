#pragma once

#include "TetoEngine/core/Window.hpp"
#include "TetoEngine/core/registry/TextureRegistry.hpp"
#include "resource_dir.h" //extern c
// #include "TetoEngine/include/TetoEngine/core/window/Frame.hpp"

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