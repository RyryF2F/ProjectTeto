#include "EditorWindow.hpp"

tetoedit::EditorWindow::EditorWindow()
{
    _renderFrame.setSize(Vector2{100,100});
    _renderFrame.setPos(Vector2{0,0});
    std::chrono::duration<int, std::milli> test(50);

    _renderFrame.setTickInterval(test);
    _renderFrame.startTicking();
}

tetoedit::EditorWindow::~EditorWindow()
{
    _renderFrame.stopTicking();
}

void tetoedit::EditorWindow::preRun()
{
    SearchAndSetResourceDir("te_resources");
    //teto::Texture tex = Texture(LoadTexture("temp.png"));
    TexReg.load("temp", LoadTexture("temp.png"), true);
    

    // frame.setBackground(&texHand.getRegistry().get(pmle::EDITOR_TEXTURES::TEX_DEF_BACKGROUND));
    
    // Vector2 test;
    // test.x = 5;
    // test.y = 5;
    // frame.setPos(test);
    // frame.setSize(test);
}

int tetoedit::EditorWindow::onDraw()
{
    DrawTexture(TexReg.get("temp").get(), 0, 0, WHITE);
    _renderFrame.testin();

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
