#include "VertexBuffer.h"
#include "pch.h"


namespace graphics
{
	VertexBuffer::VertexBuffer(const void* vertices, const unsigned int size)
		:id(0)
	{
		// Generates vertex buffer
		GLCheck(glGenBuffers(1, &id));
		GLCheck(glBindBuffer(GL_ARRAY_BUFFER, id));
		GLCheck(glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW));
	}

	VertexBuffer::VertexBuffer(std::vector<float> vertices)
	{
		// Generates vertex buffer with std::vector
		GLCheck(glGenBuffers(1, &id));
		GLCheck(glBindBuffer(GL_ARRAY_BUFFER, id));
		GLCheck(glBufferData(GL_ARRAY_BUFFER, (unsigned int)(size(vertices) * sizeof(float)),
			&vertices[0], GL_STATIC_DRAW));
	}

	VertexBuffer::VertexBuffer(const unsigned int bufferSize)
	{
		// Generates vertex buffer of a certain size but does not assign a value 
		GLCheck(glGenBuffers(1, &id));
		GLCheck(glBindBuffer(GL_ARRAY_BUFFER, id));
		GLCheck(glBufferData(GL_ARRAY_BUFFER, bufferSize, NULL, GL_DYNAMIC_DRAW));
	}

	void VertexBuffer::Delete()
	{
		GLCheck(glDeleteBuffers(1, &id));
	}

	void VertexBuffer::Bind() const
	{
		GLCheck(glBindBuffer(GL_ARRAY_BUFFER, id));
	}

	void VertexBuffer::Unbind() const
	{
		GLCheck(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	void VertexBuffer::PushLayout(unsigned int layoutSize, unsigned int type, bool normalized)
	{
		// Pushes the layout of a vertex attribute and calculates stride of the data
		stride += GetSizeOfType(type)* layoutSize;
		vbLayout.push_back(std::forward_as_tuple(layoutSize, type, normalized));
	}

	unsigned int VertexBuffer::GetSizeOfType(unsigned int type)
	{
		// Equates openGL numerical macros to their size in bytes
		switch (type)
		{
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:   return 4;
		case GL_UNSIGNED_BYTE:  return 1;
		}
		return -1;
	}
}