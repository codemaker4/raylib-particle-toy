cmake_minimum_required(VERSION 3.26)

project(raylib-particle-toy)

find_package(raylib 4.0 REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS On)

add_executable(${PROJECT_NAME}
    main.cpp
    particle.h
)

target_link_libraries(${PROJECT_NAME} raylib)

