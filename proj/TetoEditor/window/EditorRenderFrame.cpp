#include "EditorRenderFrame.hpp"

tetoedit::EditorRenderFrame::~EditorRenderFrame()
{
   
}

void tetoedit::EditorRenderFrame::onTick()
{
    RenderFrame::onTick(); //base
    
    std::cout << "tick" << std::endl;
    TraceLog(LOG_INFO, "ticking");
    _temp++;
}

void tetoedit::EditorRenderFrame::testin()
{
    TraceLog(LOG_INFO, ">> " + _temp);
}