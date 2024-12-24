#include "EditorWindow.hpp"

tetoedit::EditorWindow::EditorWindow()
{

}

tetoedit::EditorWindow::~EditorWindow()
{

}

void tetoedit::EditorWindow::preRun()
{
    // frame.setBackground(&texHand.getRegistry().get(pmle::EDITOR_TEXTURES::TEX_DEF_BACKGROUND));

    // Vector2 test;
    // test.x = 5;
    // test.y = 5;
    // frame.setPos(test);
    // frame.setSize(test);
}

int tetoedit::EditorWindow::onDraw()
{
    
    // frame.draw();
    DrawSphere(Vector3{500,500,0}, 300, WHITE);
    return 0;
}

int tetoedit::EditorWindow::onUpdate()
{
    return 0;
}

int tetoedit::EditorWindow::postRun()
{
    
    return 0;
}
