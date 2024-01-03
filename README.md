# raylib-particle-toy

Just wanna play? Run main.exe

All my source code is in main.cpp and particle.h.<br>
The entire repo is a VSCode project, so you can also open this with VSCode.

This project uses the raylib library. Go to https://www.raylib.com/ for more info.

## Build project using CMake
The project comes with a working CMakeLists.txt and [CMakePresets.json](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html#manual:cmake-presets(7)) making it easy to build it on your own.
### Prerequisites
Apart from a C/C++ compiler the following software needs to be installed for building with CMake:
 - [CMake](https://cmake.org) 3.26 or later
 - [raylib](https://www.raylib.com) 4 or later
 - [Ninja](https://ninja-build.org) (not a strict requirement, either install it or use another generator)
### How to build & run
1. run `cmake --preset=default` in the project directory
1. run `cmake --build --preset=default` in the project directory
1. run the executable "raylib-particle-toy" from the "build" folder in the project directory
