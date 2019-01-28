#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"


namespace graphics
{

	class VertexArray
	{
	public:
		VertexArray();
		void Delete();
		void Bind() const;
		void Unbind() const;
		void BindIBO(const IndexBuffer& IBO) const;
		void SetInOne(const VertexBuffer& vb);
		void Set(const VertexBuffer& vb, const int vertexArrayPos);
		inline GLuint GetId() const { return id; };

	private:
		GLuint id;
		unsigned int stride;

	};
}