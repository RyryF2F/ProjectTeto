#pragma once

#include "TetoEngine/program/window/Frame.hpp"
#include <iostream>

#include <string>

namespace tetoedit
{

    class EditorRenderFrame : public teto::RenderFrame
    {
        public:

            using RenderFrame::RenderFrame;
            //EditorRenderFrame();

            ~EditorRenderFrame();

            void onTick() override;

            void testin();
        private:
            int _temp = 0;
    };
}