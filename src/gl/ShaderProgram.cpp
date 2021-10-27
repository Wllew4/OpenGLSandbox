#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* vert, const char* frag)
{
    vertexShader(vert);
    fragmentShader(frag);
}

GLuint ShaderProgram::get()
{
    return program;
}

GLuint ShaderProgram::vertexShader(const char* source)
{
    GLuint shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    glAttachShader(program, shader);

    return shader;
}

GLuint ShaderProgram::fragmentShader(const char* source)
{
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