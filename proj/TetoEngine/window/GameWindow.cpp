#include "include/window/GameWindow.hpp"

teto::GameWindow::GameWindow()
{

}

teto::GameWindow::~GameWindow()
{
    CloseWindow();
}

int teto::GameWindow::run()
{
    updateConfigFlags();
    TraceLog(LOG_INFO, "preInit");
    InitWindow(WIN_SIZE.x, WIN_SIZE.y, WIN_NAME.c_str());
    TraceLog(LOG_INFO, "postInit");
    preRun();

    while (!WindowShouldClose())
    {
        onUpdate();
        draw();
    }
    postRun();
    return 0;
}

int teto::GameWindow::draw()
{
    BeginDrawing();
    onDraw();
    EndDrawing();
    return 0;
}

void teto::GameWindow::preRun()
{
}

int teto::GameWindow::onUpdate()
{
    return 0;
}
int teto::GameWindow::onDraw()
{
    return 0;
}

int teto::GameWindow::postRun()
{
    return 0;
}

void teto::GameWindow::updateConfigFlags()
{
    unsigned int FLAGS = 0;

    for (ConfigFlags flag : WIN_CONFIG_FLAGS)
    {
        FLAGS |= flag;
    }
    SetConfigFlags(FLAGS);
}


/* GETTERS */
std::set<ConfigFlags> const& teto::GameWindow::getConfigFlags()
{
    return this->WIN_CONFIG_FLAGS;
}

std::string const& teto::GameWindow::getWinName()
{
    return this->WIN_NAME;
}

Vector2 const& teto::GameWindow::getWinSize()
{
    return this->WIN_SIZE;
}


/* SETTERS */
void teto::GameWindow::setConfigFlags(std::set<ConfigFlags> configFlags)
{
    this->WIN_CONFIG_FLAGS = configFlags;
}
void teto::GameWindow::setWinName(std::string winName)
{
    this->WIN_NAME = winName;
}
void teto::GameWindow::setWinSize(Vector2 winSize)
{
    this->WIN_SIZE = winSize;
}

/* WIN FLAG HELPERS*/
bool teto::GameWindow::hasFlag(ConfigFlags const& configFlag)
{
    if (WIN_CONFIG_FLAGS.find(configFlag) != WIN_CONFIG_FLAGS.end())
    {
        return true;
    }
    return false;
}

bool teto::GameWindow::addConfigFlag(ConfigFlags configFlag)
{
   std::pair<std::set<ConfigFlags>::iterator,bool> ret = this->WIN_CONFIG_FLAGS.insert(configFlag);
   return ret.second;
}

bool teto::GameWindow::removeConfigFlag(ConfigFlags configFlag)
{
    if (this->WIN_CONFIG_FLAGS.erase(configFlag) != 0)
    {
        return true;
    }
    return false;
}