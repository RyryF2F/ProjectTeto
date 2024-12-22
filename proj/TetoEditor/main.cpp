extern "C"
{
#include "resource_dir.h"
}

#include "window/EditorWindow.hpp"

int main()
{

    tetoedit::EditorWindow* editorWindow = new tetoedit::EditorWindow();
    std::set<ConfigFlags> configSet{FLAG_VSYNC_HINT, FLAG_WINDOW_HIGHDPI};
    editorWindow->setConfigFlags(configSet);
    Vector2 winSize;
    winSize.x = 800;
    winSize.y = 400;
    editorWindow->setWinSize(winSize);
    editorWindow->setWinName("Post Master Level Editor");
    
    SearchAndSetResourceDir("resources");

    editorWindow->run();

    delete editorWindow;
    editorWindow = nullptr;

    return 0;
}