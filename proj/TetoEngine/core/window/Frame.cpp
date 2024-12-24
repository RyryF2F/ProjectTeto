#include "TetoEngine/core/window/Frame.hpp"

/**
 * Frame
 */
teto::Frame::Frame()
{

}

teto::Frame::Frame(Vector2 pos, Vector2 size) : _pos(pos), _size(size)
{

}

teto::Frame::Frame(Vector2 pos, Vector2 size, teto::Texture* background) : _pos(pos), _size(size), _background(background)
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
void teto::Frame::setBackground(teto::Texture* background)
{
    _background = background;
}

void teto::Frame::draw()
{
    DrawTexture(_background->get(), _pos.x, _pos.y, WHITE);
}


/**
 * TextFrame
 */
teto::TextFrame::TextFrame(Vector2 pos, Vector2 size, std::string const& text) 
{
    setPos(pos);
    setSize(size);
    setText(text);
}

void teto::TextFrame::setText(std::string const& text)
{
    _text = text;
}