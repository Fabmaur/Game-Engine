#include "pch.h"
#include "VertexArray.h"


namespace graphics
{

	VertexArray::VertexArray()
		:id(0)
	{
		GLCheck(glGenVertexArrays(1, &id));
	}

	void VertexArray::Delete()
	{
		GLCheck(glDeleteVertexArrays(1, &id));
	}

	void VertexArray::Bind() const
	{
		GLCheck(glBindVertexArray(id));
	}

	void VertexArray::Unbind() const
	{
		GLCheck(glBindVertexArray(0));
	}

	void VertexArray::BindIBO(const IndexBuffer& IBO) const
	{
		Bind();
		IBO.Bind();
		Unbind();
		IBO.Unbind();
	}

	void VertexArray::SetVertexAttribArray(const VertexBuffer& vb)
	{
		Bind();
		vb.Bind();
		const auto& layout = vb.GetLayout();
		unsigned int offset = 0;
		for (std::size_t i = 0; i < layout.size(); i++)
		{
			const auto&[layoutSize, type, normalized] = layout[i];
			GLCheck(glVertexAttribPointer(i, layoutSize, type, normalized, vb.GetStride(), (const void*)offset));
			GLCheck(glEnableVertexAttribArray(i));
			offset += layoutSize * graphics::VertexBuffer::GetSizeOfType(type);
		}
		Unbind();
		vb.Unbind();
	}

	void graphics::VertexArray::SetVertexAttrib(const VertexBuffer& vb, const int vertexArrayPos)
	{
		Bind();
		vb.Bind();
		static int offset = 0;
		const auto& layout = vb.GetLayout();
		const auto&[layoutSize, type, normalized] = layout[0];
		GLCheck(glVertexAttribPointer(vertexArrayPos,
			layoutSize,
			type,
			normalized,
			vb.GetStride(),
			(void*)(vertexArrayPos*graphics::VertexBuffer::GetSizeOfType(type))));

		GLCheck(glEnableVertexAttribArray(vertexArrayPos));
		offset += layoutSize * graphics::VertexBuffer::GetSizeOfType(type);
		Unbind();
		vb.Unbind();

	}
}