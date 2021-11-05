#include "NewRenderer.h"

#include <vec2.hpp>
#include "gl/shaders.h"

void NewRenderer::run()
{
    std::vector<glm::vec2> vertices =
    {
        glm::vec2(0.5,  0.0),
        glm::vec2(-0.5, 0.0),
        glm::vec2(0.0,  0.5)
    };

    std::vector<GLuint> indices =
    {
        0, 1, 2
    };

    ShaderProgram standardShader = ShaderProgram(Standard_vert, Standard_frag);

    Material mat = Material(standardShader);

    Sprite pleasework (vertices, indices, mat);

    glBindAttribLocation(standardShader.get(), 0, "a_vertex");

    renderer.queueVAO(&pleasework);

    renderer.startRenderLoop();
}

void NewRenderer::update(float deltaTime)
{
    
}