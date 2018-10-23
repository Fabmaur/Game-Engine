#include "VertexBuffer.h"

using namespace graphics;

VertexBuffer::VertexBuffer(const void* vertices, const unsigned int size)
{
	GLCall(glGenBuffers(1, &id));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, id));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &id));
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, id));
}

void VertexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
