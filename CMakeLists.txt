if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif (CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif (CMAKE_HOST_UNIX)
    set(LINUX 1)
endif ()

set(SOURCE_FILES main/1Triangle.cpp main/2ProgramingStart.cpp main/src/ main/include/MineUtils.h main/src/MineUtils.cpp main/2TestGLUT.cpp)

if (MACOS)
    cmake_minimum_required(VERSION 3.16)
    project(OpenGLLearn)

    set(CMAKE_CXX_STANDARD 14)

    # 添加头文件
    set(GLEW_H /usr/local/Cellar/glew/2.2.0_1/include/GL)
    set(GLFW_H /usr/local/Cellar/glfw/3.3.2/include/GLFW)
    set(PROGRAM_INCLUDE ${PROJECT_SOURCE_DIR}/main/include)
    include_directories(${GLEW_H} ${GLFW_H} ${PROGRAM_INCLUDE})

    # 添加目标链接
    set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.dylib)
    set(GLFW_LINK /usr/local/Cellar/glfw/3.3.2/lib/libglfw.3.dylib)
    link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

    # 执行编译命令
#    set(SOURCE_FILES main/1Triangle.cpp main/2ProgramingStart.cpp main/src/ main/include/MineUtils.h main/src/MineUtils.cpp)
    add_executable(OpenGLLearn ${SOURCE_FILES})

    if (APPLE)
        target_link_libraries(OpenGLLearn "-framework OpenGL")
        target_link_libraries(OpenGLLearn "-framework GLUT")
    endif()
elseif (WINDOWS)
    cmake_minimum_required(VERSION 3.16)
    project(OpenGLLearn)

    set(CMAKE_CXX_STANDARD 14)
    set("PROGRAM_INCLUDE ${PROJECT_SOURCE_DIR}/main/include")

    link_directories("C:/Environments/OpenGL/lib")
    include_directories("C:/Environments/OpenGL/include ${PROGRAM_INCLUDE}")

#    add_executable(OpenGLLearn src/glad.c main/1Triangle.cpp main/2ProgramingStart.cpp main/src/ main/include/MineUtils.h main/src/MineUtils.cpp main/2TestGLUT.cpp)
    add_executable(OpenGLLearn src/glad.c ${SOURCE_FILES})
    target_link_libraries(OpenGLLearn -lfreeglut -lopengl32 libglfw3.a glew32.lib glew32s.lib) # freeglut 版本

elseif (LINUX)
endif ()

