// GL1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
using namespace std;

// window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    if (!glfwInit())
    {
        cout << "GLFW not initiated" << endl;
        glfwTerminate();
        return;
    }

    // glfw properties
    // set glfw version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // core profile is not backward compatible
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

}


