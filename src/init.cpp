#include <glIncludes.h>
#include <iostream>

GLFWwindow* init(int width, int height, const char* title)
{
    if(!glfwInit())
    {
        std::cerr << "ERROR: Failed to initialize GLFW\n" << std::endl;
        exit(1);
    }
    glewExperimental = GL_TRUE;

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        std::cerr << "ERROR: could not open window with GLFW3\n";
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);
    glewInit();
    
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    return window;
}