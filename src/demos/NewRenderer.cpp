#include "NewRenderer.h"

#include <vec2.hpp>
#include <fstream>
#include <iostream>

std::string loadFile(std::string path)
{
    return std::string(std::istreambuf_iterator<char>(std::ifstream(path.c_str())), std::istreambuf_iterator<char>());
}

std::string Standard_vert = loadFile("shaders/Standard.vert");
std::string Standard_frag = loadFile("shaders/Standard.frag");

void NewRenderer::run()
{
    std::vector<glm::vec2> vertices =
    {
        glm::vec2(0.5,  -0.5),
        glm::vec2(-0.5, -0.5),
        glm::vec2(0.0,   0.5)
    };

    std::vector<GLuint> indices =
    {
        0, 1, 2
    };

    ShaderProgram standardShader = ShaderProgram(Standard_vert.c_str(), Standard_frag.c_str());

    Material mat = Material(standardShader);

    Sprite prettyTriangle (vertices, indices, mat);

    renderer.queueSprite(&prettyTriangle);

    renderer.startRenderLoop();
}

void NewRenderer::update(float deltaTime)
{
    
}