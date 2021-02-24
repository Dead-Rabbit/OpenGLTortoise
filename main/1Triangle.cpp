#include <iostream>
#include <glew.h>
#include <glfw3.h>

using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    //如果按下ESC，把windowShouldClose设置为True，外面的循环会关闭应用
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    std::cout << "ESC" << mode;
}

// 输出三角
int run_thr(){

    if(!glfwInit())
        return -1;

    //创建窗口以及上下文
    GLFWwindow* window = glfwCreateWindow(640, 480, "hello world", NULL, NULL);
    if(!window)
    {
        //创建失败会返回NULL
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

//    glfwSetKeyCallback(window, key_callback); //注册回调函数
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.2, 0.3, 0.3, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0); //Red
        glVertex3f(0, 1, 0);
        glColor3f(0, 1, 0); //Green
        glVertex3f(-1, -1, 0);
        glColor3f(0, 0, 1); //Blue
        glVertex3f(1, -1, 0);

        //结束一个画图步骤
        glEnd();

        /******交换缓冲区，更新window上的内容******/
        glfwSwapBuffers(window);
    }
    glfwTerminate();

    return 0;
}
