#include "VertexArray.h"

VertexArray::VertexArray()
	:id(0), stride(0)
{
	GLCall(glGenVertexArrays(1, &id));
}

VertexArray::~VertexArray()
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

void VertexArray::Set(const VertexBuffer& vb, const VBLayout& vbl)
{
	Bind();
	vb.Bind();
	const auto& layout = vbl.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < layout.size(); i++)
	{
	glVertexAttribPointer(i, layout[i].size, layout[i].type,  layout[i].normalized, vbl.GetStride(), (const void*)offset);
	GLCall(glEnableVertexAttribArray(i));
	offset += VBElements::GetSizeOfType(layout[i].type) * layout[i].size;
	}
}
