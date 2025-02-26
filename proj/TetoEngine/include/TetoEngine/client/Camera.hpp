#pragma once

#include "raylib.h"
#include "base/Drawable.hpp"

/**
 * Contains types of Cameras, with moving support
 */


namespace teto
{
    /**
     * 3D Camera that is setup with keybind inputs, that can be changed
     */
    class PlayerCamera : public Drawable
    {
        public:

        
        void draw() override;

        private:
            ::Camera3D _camera = { 0 }; //c way

            
    };
}