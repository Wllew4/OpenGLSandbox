#include "NewRenderer.h"

#include <vec2.hpp>
#include <fstream>
#include <iostream>

#include "lua.hpp"

std::string loadFile(std::string path)
{
    return std::string(std::istreambuf_iterator<char>(std::ifstream(path.c_str())), std::istreambuf_iterator<char>());
}

std::string Standard_vert = loadFile("shaders/Standard.vert");
std::string Standard_frag = loadFile("shaders/Standard.frag");

static int getHello(lua_State* L)
{
    lua_len(L, 1);
    size_t len = lua_tonumber(L, -1);
    std::cout << len << std::endl;
    lua_pop(L, 1);
    // lua_gettable(L, -3);
    for(uint8_t i = 1; i <= len; i++)
    {
        // std::cout << lua_istable(L, -1);
        lua_pushinteger(L, i);
        lua_gettable(L, -2);
        std::cout << lua_tointeger(L, -1) << ": " << lua_tointeger(L, -1) << std::endl;
        lua_pop(L, 1);
    }
    // lua_pushnumber(L, lua_tonumber(L, 1));
    return 1;
}

void NewRenderer::run()
{

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    lua_register(L, "getHello", getHello);

    luaL_dofile(L, "sandbox/sandbox.lua");


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