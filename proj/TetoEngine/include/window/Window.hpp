#pragma once

// extern "C" {
// #include "raylib.h"
// }
#include "raylib.h"
#include <set>
#include <string>

/**
 * Class to create new Window
 */
namespace teto
{


    class Window
    {
        public:

        Window();
        ~Window();
        

        int run(); /* Calls the Window to initalize and begins loop*/

        virtual void preRun(); /* After Window is Initialized, but before any draw/update calls */
        virtual int onUpdate(); /* override for inner update loop*/
        int draw(); /* for handling internal calls to draw, including draw loop */
        virtual int onDraw(); /* override for inner draw loop*/
        virtual int postRun(); /* After loop closes but before window is closed */

        void updateConfigFlags();


        std::set<ConfigFlags> const& getConfigFlags();
        std::string const& getWinName();
        Vector2 const& getWinSize();


        void setConfigFlags(std::set<ConfigFlags> configFlags);
        void setWinName(std::string winName);
        void setWinSize(Vector2 winSize);

        bool hasFlag(ConfigFlags const& configFlag);
        bool addConfigFlag(ConfigFlags configFlag);
        bool removeConfigFlag(ConfigFlags configFlag);


        protected:



        private:
            std::set<ConfigFlags> WIN_CONFIG_FLAGS;
            std::string WIN_NAME;
            Vector2 WIN_SIZE;
    };
}