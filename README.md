
# Project Teto


This project and repository is a video game project I am working on to personally further my knowledge of C and C++. Focusing heavily on both code management, and modern (C++17) CPP development.  This is **not a finished a product**. 

## Build Requirements
This project uses **Raylib** as a core library. This may change, however for ease of use I will be using Raylib, and it's associated modules, instead of making OpenGL/ANGLE calls directly. This helps me ensure compatability will be covered with little work. 

- Raylib (Using OpenGL 4.3)
## Build Instructions

This project will be changing constantly, and if you come across this, and wish to build it, I am more than willing to help. However it is important to note, this project stands as a playground for me.



This project (will) contains both:

- TetoEngine - C++ Library built on top of rcore, rlgl, etc.
    -
- TetoWarGame - Initial game, for development
    -
- TetoEditor - Program to edit games built on TetoEngine
    -

You will need to download raylib, and place it in /build/external, and compile it.
All code compilation should be done using MinGW-w64, using gcc only, as that is what I will be building on.