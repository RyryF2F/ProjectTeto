#pragma once
#include "Frame.hpp"

/**
 * Some unique window for rendering opengl, this is to match frame used further ahead, which
 * will only handle framing and such
 */
namespace teto
{
    class RenderFrame : public Frame
    {
        using Frame::Frame;

        void draw() override;

        private:
            Camera _camera;
    }
}
