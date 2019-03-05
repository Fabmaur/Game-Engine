#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"


namespace graphics
{
	/*Vertex Array class creates an opengl vertex array object which specifies
	how vertex data is stored in a VBO. It also holds are IBO data and should be
	bound when you want to draw the specified object.*/

	class VertexArray
	{
	public:
		VertexArray();
		void Delete();
		void Bind() const;
		void Unbind() const;
		void BindIBO(const IndexBuffer& IBO) const;
		void SetVertexAttribArray(const VertexBuffer& vb);
		void SetVertexAttrib(const VertexBuffer& vb, const int vertexArrayPos);
		inline unsigned int GetId() const { return id; };

	private:
		unsigned int id;

	};
}