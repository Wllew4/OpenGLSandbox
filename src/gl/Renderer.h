#pragma once

#include "glIncludes.h"
#include "VertexArray.h"
#include <vector>

class Renderer
{
private:
    std::vector<VertexArray> queue;
    GLFWwindow* window;
    
public:
    Renderer(GLFWwindow* window);

    void queueVAO(VertexArray vao);

    void startRenderLoop();
};