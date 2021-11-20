#pragma once

#include <string>

#include <gl/glIncludes.h>
#include <vec2.hpp>
#include "gl/Sprite.h"
#include "gl/Renderer.h"
#include <fstream>
#include <iostream>

#include "lua.hpp"

lua_State* L = luaL_newstate();

std::string loadFile(lua_State* L, std::string path)
{
    luaL_dofile(L, "getfile.lua");
    lua_getglobal(L, "GetFile");
    lua_pushstring(L, path.c_str());
    lua_pcall(L, 1, 1, 0);
    std::string out = std::string(lua_tostring(L, -1));
    lua_pop(L, 1);
    std::cout << out << std::endl;
    return out;
}


std::vector<GLuint> indices = std::vector<GLuint>(3);
std::vector<glm::vec2> vertices = std::vector<glm::vec2>();

static int getHello(lua_State* L)
{
    lua_pushstring(L, "indices");   // 1: sprite 2: string
    lua_gettable(L, -2);            // 1: sprite 2: indices
    std::cout << lua_type(L, 1);    // 5 -> LUA_TTABLE
    lua_len(L, -1);                 // 1: sprite 2: indices 3: length
    int64_t len = lua_tointeger(L, -1);
    std::cout << "size:" << len << std::endl;
    std::cout << "type:" << lua_type(L, 1) << std::endl;
    lua_pop(L, 1);                  // 1: sprite 2: indices
    std::cout << "type:" << lua_type(L, 1) << std::endl;
    for(uint32_t i = 1; i <= len; i++)
    {
        lua_pushinteger(L, i);
        lua_gettable(L, -2);
        std::cout << i << ": " << lua_tointeger(L, -1) << std::endl;
        indices.emplace_back((GLuint)lua_tointeger(L, -1));
        lua_pop(L, 1);
    }
    lua_pop(L, 1);

    // 1: sprite

    lua_pushstring(L, "vertices");   // 1: sprite 2: string
    lua_gettable(L, -2);            // 1: sprite 2: vertices
    std::cout << lua_type(L, 1);    // 5 -> LUA_TTABLE
    lua_len(L, -1);                 // 1: sprite 2: vertices 3: length
    len = lua_tointeger(L, -1);
    std::cout << "size:" << len << std::endl;
    std::cout << "type:" << lua_type(L, -1) << std::endl;
    lua_pop(L, 1);                  // 1: sprite 2: vertices
    std::cout << "type:" << lua_type(L, -1) << std::endl;
    for(uint32_t i = 1; i <= len; i += 2)
    {
        lua_pushinteger(L, i);
        lua_gettable(L, -2);
        std::cout << i << ": " << lua_tonumber(L, -1) << std::endl;
        glm::vec2 vec;
        vec.x = (float)lua_tonumber(L, -1);
        lua_pop(L, 1);
        lua_pushinteger(L, i + 1);
        lua_gettable(L, -2);
        std::cout << i+1 << ": " << lua_tonumber(L, -1) << std::endl;
        vec.y = (float)lua_tonumber(L, -1);
        lua_pop(L, 1);
        vertices.emplace_back(vec);
    }
    lua_pop(L, 1);
    return 1;
}

class Sandbox
{
private:
    Renderer renderer = Renderer(920, 540, "Hello!", *this);
public:
    void run(std::string file)
    {
        luaL_openlibs(L);

        lua_register(L, "getHello", getHello);

        luaL_dofile(L, "sandbox/sandbox.lua");
        
        std::string Standard_vert = loadFile(L, "shaders/Standard.vert");
        std::string Standard_frag = loadFile(L, "shaders/Standard.frag");

        ShaderProgram standardShader = ShaderProgram(Standard_vert.c_str(), Standard_frag.c_str());

        Material mat = Material(standardShader);

        Sprite prettyTriangle (vertices, indices);

        renderer.queueSprite(&prettyTriangle, mat);

        renderer.startRenderLoop();
    }
};