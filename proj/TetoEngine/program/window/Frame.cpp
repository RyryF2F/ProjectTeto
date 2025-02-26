#include "TetoEngine/program/window/Frame.hpp"

/**
 * Frame
 */
teto::Frame::Frame()
{

}

teto::Frame::Frame(Vector2 pos, Vector2 size) : _pos(pos), _size(size)
{

}

void teto::Frame::setPos(Vector2 const& pos)
{
    _pos = pos;
}
void teto::Frame::setSize(Vector2 const& size)
{
    _size = size;
}


/**
 * Render Frame
 */

teto::RenderFrame::RenderFrame()
{
    TraceLog(LOG_INFO, "RENDERFRAME");
}

teto::RenderFrame::RenderFrame(Vector2 pos, Vector2 size) : Frame::Frame(pos, size)
{
    TraceLog(LOG_INFO, "RENDERFRAME");
}

// teto::RenderFrame::~RenderFrame()
// {
// }

void teto::RenderFrame::onTick()
{
    TraceLog(LOG_INFO, "ontick");
}