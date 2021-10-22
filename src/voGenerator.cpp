#include "voGenerator.h"
#include <iostream>
#include <fstream>
#include <sstream>

const char* getFile(const char* path)
{
    return (std::stringstream() << std::ifstream(path).rdbuf()).str().c_str();
}

GLuint vertexBuffer(float data[], size_t size)
{
    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    return vbo;
}

GLuint vertexArray()
{
    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    return vao;
}

void bindVBOtoVAO(const GLuint& vao, const GLuint& vbo, int index)
{
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(index, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(index);
}

void appendShader(GLuint shader_prog, const char* file, GLuint type)
{
    const char* source = getFile(file);

    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    glAttachShader(shader_prog, shader);
}

