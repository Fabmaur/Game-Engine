#include "IndexBuffer.h"
#include "GL/glew.h"
#include "debug/GLDebug.h"

IndexBuffer::IndexBuffer(const void* indices, const unsigned int count)
{
	GLCall(glGenBuffers(1, &id));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &id));
}

void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
}

void IndexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
