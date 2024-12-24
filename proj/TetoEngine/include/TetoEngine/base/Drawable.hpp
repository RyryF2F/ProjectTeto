#pragma once

/**
 * Base class for anything that has explicit code to be ran when drawn
 * e.g. a class Circle, with values that with draw runs DrawCircle() using rmodels
 */
namespace teto
{
    class Drawable
    {
        public:
            virtual void draw() = 0;
    };
}