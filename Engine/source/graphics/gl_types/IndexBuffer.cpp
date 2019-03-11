#include "pch.h"

namespace graphics
{
	IndexBuffer::IndexBuffer(const void* indices, const unsigned int count)
		:count(count)
	{
		GLCheck(glGenBuffers(1, &id));
		GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
		GLCheck(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW));
	}

	IndexBuffer::IndexBuffer(std::vector<unsigned int>& indices)
	{
		GLCheck(glGenBuffers(1, &id));
		GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
		GLCheck(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size(indices) * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW));
	}

	IndexBuffer::IndexBuffer(const unsigned int bufferSize)
	{
		GLCheck(glGenBuffers(1, &id));
		GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
		GLCheck(glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, NULL, GL_DYNAMIC_DRAW));
	}


	void IndexBuffer::Delete()
	{
		GLCheck(glDeleteBuffers(1, &id));
	}

	void IndexBuffer::Bind() const
	{
		GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));
	}

	void IndexBuffer::Unbind() const
	{
		GLCheck(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}
}