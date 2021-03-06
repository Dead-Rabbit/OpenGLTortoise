//
// Created by 王子潇 on 2021/2/24.
//

#ifndef OPENGLLEARN_MINEUTILS_H
#define OPENGLLEARN_MINEUTILS_H

#if defined(__WIN32__)
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#else
#include <glew.h>
#include <glfw3.h>
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

using namespace std;

class MineUtils
{
private:
    static string readShaderSource(string filePath);
public:
    MineUtils();
    /**
     * 创建一个指定Shader文件的绘制程序
     * @param vertShaderPath
     * @param fragShaderPath
     * @return
     */
    static GLuint createShaderProgram(const char * vertShaderPath, const char * fragShaderPath);
};

#endif //OPENGLLEARN_MINEUTILS_H
