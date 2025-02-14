#pragma once
#include "Frame.hpp"
#include "TetoEngine/base/Ticker.hpp"

/**
 * Some unique window for rendering opengl, this is to match frame used further ahead, which
 * will only handle framing and such
 * 
 * 
 * 
 * Unique Frame that will also control ticking, good for frame and game logic
 */
namespace teto
{
    class RenderFrame : public Frame
    {
        using Frame::Frame;

        void draw() override;

        void onTick();

        private:
            Camera _camera;
            Ticker<20> ticker(std::function<void()>(onTick));
    };;
}
