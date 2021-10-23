#include "ShaderProgram.h"

#include <fstream>
#include <sstream>
#include <iostream>

GLuint ShaderProgram::get()
{
    return program;
}

const char* getFile(const char* path)
{
    std::string file = (std::stringstream() << std::ifstream(path).rdbuf()).str().c_str();
    // std::cout << file;
    return file.c_str();
}

GLuint ShaderProgram::vertexShader(const char* file)
{
    const char* source = getFile(file);

    GLuint shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    glAttachShader(program, shader);

    return shader;
}

GLuint ShaderProgram::fragmentShader(const char* file)
{
    const char* source = getFile(file);

    GLuint shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    glAttachShader(program, shader);

    return shader;
}

void ShaderProgram::compile()
{
    glBindAttribLocation(program, VERTEX_BUFFER_INDEX, VERTEX_BUFFER_NAME);
    glBindAttribLocation(program, COLOR_BUFFER_INDEX, COLOR_BUFFER_NAME);
    glLinkProgram(program);
}