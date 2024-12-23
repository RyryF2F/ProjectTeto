#include "TetoEngine/Window.hpp"

teto::Window::Window()
{

}

teto::Window::~Window()
{
    CloseWindow();
}

int teto::Window::run()
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

int teto::Window::draw()
{
    BeginDrawing();
    onDraw();
    EndDrawing();
    return 0;
}

void teto::Window::preRun()
{
}

int teto::Window::onUpdate()
{
    return 0;
}
int teto::Window::onDraw()
{
    return 0;
}

int teto::Window::postRun()
{
    return 0;
}

void teto::Window::updateConfigFlags()
{
    unsigned int FLAGS = 0;

    for (ConfigFlags flag : WIN_CONFIG_FLAGS)
    {
        FLAGS |= flag;
    }
    SetConfigFlags(FLAGS);
}


/* GETTERS */
std::set<ConfigFlags> const& teto::Window::getConfigFlags()
{
    return this->WIN_CONFIG_FLAGS;
}

std::string const& teto::Window::getWinName()
{
    return this->WIN_NAME;
}

Vector2 const& teto::Window::getWinSize()
{
    return this->WIN_SIZE;
}


/* SETTERS */
void teto::Window::setConfigFlags(std::set<ConfigFlags> configFlags)
{
    this->WIN_CONFIG_FLAGS = configFlags;
}
void teto::Window::setWinName(std::string winName)
{
    this->WIN_NAME = winName;
}
void teto::Window::setWinSize(Vector2 winSize)
{
    this->WIN_SIZE = winSize;
}

/* WIN FLAG HELPERS*/
bool teto::Window::hasFlag(ConfigFlags const& configFlag)
{
    if (WIN_CONFIG_FLAGS.find(configFlag) != WIN_CONFIG_FLAGS.end())
    {
        return true;
    }
    return false;
}

bool teto::Window::addConfigFlag(ConfigFlags configFlag)
{
   std::pair<std::set<ConfigFlags>::iterator,bool> ret = this->WIN_CONFIG_FLAGS.insert(configFlag);
   return ret.second;
}

bool teto::Window::removeConfigFlag(ConfigFlags configFlag)
{
    if (this->WIN_CONFIG_FLAGS.erase(configFlag) != 0)
    {
        return true;
    }
    return false;
}