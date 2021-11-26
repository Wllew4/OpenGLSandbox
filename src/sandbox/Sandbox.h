#pragma once

#include <string>

#include "gl/Mesh2D.h"
#include "gl/Renderer.h"
#include <filesystem>

#include "util.h"

class Sandbox
{
private:
    Renderer renderer = Renderer(920, 540, "Hello!", *this);

public:
    Sandbox(char* exe)
    {
        std::filesystem::current_path(std::filesystem::path(exe).parent_path());
    }

    void run(std::string file)
    {
        std::vector<GLuint> indices =
        {
            0, 1, 2
        };
        
        std::vector<glm::vec2> vertices =
        {
            glm::vec2( 0.5, -0.5),
            glm::vec2(-0.5, -0.5),
            glm::vec2( 0.0,  0.5)
        };

        std::string Standard_vert = loadFile("shaders/Standard.vert");
        std::string Standard_frag = loadFile("shaders/Standard.frag");

        ShaderProgram standardShader = ShaderProgram(Standard_vert.c_str(), Standard_frag.c_str());
        
        Material mat = Material(standardShader);

        Mesh2D prettyTriangle (vertices, indices);

        renderer.queueSprite(&prettyTriangle, mat);

        renderer.startRenderLoop();
    }
};