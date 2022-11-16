#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cstdio>


namespace shb{

class sWindow{
 public:
    sWindow(int height, int width);

    void initWindow();
    void makeContextCurrent();
    void destroy();

    int _width;
    int _height;
    GLFWwindow* _handle;
};



}//namespace shb