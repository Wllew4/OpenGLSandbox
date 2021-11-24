#pragma once

#include <iostream>
#include <vector>
#include "vec2.hpp"
#include "gl/glIncludes.h"
#include "lua.hpp"
#include "gl/ShaderProgram.h"

std::vector<GLuint> indices = std::vector<GLuint>(3);
std::vector<glm::vec2> vertices = std::vector<glm::vec2>();

class LuaHander
{
private:
    lua_State* L = luaL_newstate();

    static int loadMesh2D(lua_State* L)
    {
        lua_pushstring(L, "indices");   // 1: sprite 2: string
        lua_gettable(L, -2);            // 1: sprite 2: indices
        // std::cout << lua_type(L, 1);    // 5 -> LUA_TTABLE
        lua_len(L, -1);                 // 1: sprite 2: indices 3: length
        int64_t len = lua_tointeger(L, -1);
        // std::cout << "size:" << len << std::endl;
        // std::cout << "type:" << lua_type(L, 1) << std::endl;
        lua_pop(L, 1);                  // 1: sprite 2: indices
        // std::cout << "type:" << lua_type(L, 1) << std::endl;
        for(uint32_t i = 1; i <= len; i++)
        {
            lua_pushinteger(L, i);
            lua_gettable(L, -2);
            // std::cout << i << ": " << lua_tointeger(L, -1) << std::endl;
            indices.emplace_back((GLuint)lua_tointeger(L, -1));
            lua_pop(L, 1);
        }
        lua_pop(L, 1);

        // 1: sprite

        lua_pushstring(L, "vertices");   // 1: sprite 2: string
        lua_gettable(L, -2);            // 1: sprite 2: vertices
        // std::cout << lua_type(L, 1);    // 5 -> LUA_TTABLE
        lua_len(L, -1);                 // 1: sprite 2: vertices 3: length
        len = lua_tointeger(L, -1);
        // std::cout << "size:" << len << std::endl;
        // std::cout << "type:" << lua_type(L, -1) << std::endl;
        lua_pop(L, 1);                  // 1: sprite 2: vertices
        // std::cout << "type:" << lua_type(L, -1) << std::endl;
        for(uint32_t i = 1; i <= len; i += 2)
        {
            lua_pushinteger(L, i);
            lua_gettable(L, -2);
            // std::cout << i << ": " << lua_tonumber(L, -1) << std::endl;
            glm::vec2 vec;
            vec.x = (float)lua_tonumber(L, -1);
            lua_pop(L, 1);
            lua_pushinteger(L, i + 1);
            lua_gettable(L, -2);
            // std::cout << i+1 << ": " << lua_tonumber(L, -1) << std::endl;
            vec.y = (float)lua_tonumber(L, -1);
            lua_pop(L, 1);
            vertices.emplace_back(vec);
        }
        lua_pop(L, 1);
        return 1;
    }

    static int loadShader(lua_State* L)
    {
        lua_pushnumber(L, 1);
        lua_gettable(L, -2);
        // standardShader.vertexShader(lua_tostring(L, -1));
        std::cout << lua_tostring(L, -1);
        lua_pop(L, 1);
        lua_pushnumber(L, 2);
        lua_gettable(L, -2);
        std::cout << lua_tostring(L, -1);
        // standardShader.fragmentShader(lua_tostring(L, -1));
        lua_pop(L, 1);
        // standardShader.link();
        std::cout << lua_type(L, -2);
        return 1;
    }

public:
    LuaHander()
    {
        luaL_openlibs(L);

        lua_register(L, "loadMesh2D", loadMesh2D);
        lua_register(L, "loadShader", loadShader);
    }

    void doFile(std::string path)
    {
        luaL_dofile(L, path.c_str());
    }


};