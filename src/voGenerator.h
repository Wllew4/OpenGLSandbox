#pragma once
#include <glIncludes.h>

GLuint vertexBuffer(float data[], size_t size);
GLuint vertexArray();
void bindVBOtoVAO(const GLuint& vao, const GLuint& vbo, int index);
void appendShader(GLuint shader, const char* file, GLuint type);