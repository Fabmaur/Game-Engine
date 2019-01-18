#include "VertexArray.h"

using namespace graphics;

VertexArray::VertexArray()
	:id(0), stride(0)
{
	GLCall(glGenVertexArrays(1, &id));
}

void VertexArray::Delete()
{
	GLCall(glDeleteVertexArrays(1, &id));
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(id));
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}

void VertexArray::SetInOne(const VertexBuffer& vb)
{
	Bind();
	vb.Bind();
	const auto& layout = vb.GetLayout();
	unsigned int offset = 0;
	for (std::size_t i = 0; i < layout.size(); i++)
	{
		const auto& [layoutSize, type, normalized] = layout[i];
		GLCall(glVertexAttribPointer(i, layoutSize, type,  normalized, vb.GetStride(), (const void*)offset));
		GLCall(glEnableVertexAttribArray(i));
		offset += layoutSize * graphics::VertexBuffer::GetSizeOfType(type);
	}
	vb.Unbind();
	Unbind();
}

void graphics::VertexArray::Set(const VertexBuffer& vb, const int vertexArrayPos)
{
	Bind();
	vb.Bind();
	static int offset = 0;
	const auto& layout = vb.GetLayout();
	const auto& [layoutSize, type, normalized] = layout[0];
	GLCall(glVertexAttribPointer(vertexArrayPos,
		layoutSize,
		type,
		normalized,
		vb.GetStride(), 
		(void*)(vertexArrayPos*graphics::VertexBuffer::GetSizeOfType(type))));
	
	GLCall(glEnableVertexAttribArray(vertexArrayPos));
	offset += layoutSize * graphics::VertexBuffer::GetSizeOfType(type);
	vb.Bind();
	Unbind();

}
