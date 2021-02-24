if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif (CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif (CMAKE_HOST_UNIX)
    set(LINUX 1)
endif ()

if (MACOS)
elseif (WINDOWS)
    cmake_minimum_required(VERSION 3.16)
    project(learn_opengl)

    set(CMAKE_CXX_STANDARD 14)
    set("PROGRAM_INCLUDE ${PROJECT_SOURCE_DIR}/main/include")

    link_directories("C:/Environments/OpenGL/lib")
    include_directories("C:/Environments/OpenGL/include ${PROGRAM_INCLUDE}")

    add_executable(learn_opengl src/glad.c main/1Triangle.cpp main/2ProgramingStart.cpp main/src/ main/include/MineUtils.h main/src/MineUtils.cpp)
    target_link_libraries(learn_opengl -lOpengl32 libglfw3.a glew32.lib glew32s.lib)
elseif (LINUX)
endif ()

