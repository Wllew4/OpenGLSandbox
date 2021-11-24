#pragma once

#include <string>

#include "gl/Sprite.h"
#include "gl/Renderer.h"
#include <filesystem>

#include "util.h"

#include "LuaHandler.h"
// ShaderProgram standardShader;

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
        LuaHander L = LuaHander();
        L.doFile("sandbox/sandbox.lua");

        std::string Standard_vert = loadFile("shaders/Standard.vert");
        std::string Standard_frag = loadFile("shaders/Standard.frag");

        ShaderProgram standardShader = ShaderProgram(Standard_vert.c_str(), Standard_frag.c_str());

        // standardShader.vertexShader(Standard_vert.c_str());
        // standardShader.fragmentShader(Standard_frag.c_str());
        // standardShader.link();
        
        Material mat = Material(standardShader);

        Sprite prettyTriangle (vertices, indices);

        renderer.queueSprite(&prettyTriangle, mat);

        renderer.startRenderLoop();
    }
};