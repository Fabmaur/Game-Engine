#include "pch.h"
#include "BatchRenderer2D.h"
#include "debug/GLDebug.h"


namespace graphics
{

	BatchRenderer2D::BatchRenderer2D(const int MAX_SHAPES, unsigned int VERTEX_SIZE)
		:MAX_SHAPES(MAX_SHAPES),
		VERTEX_SIZE(VERTEX_SIZE)
	{
		VAO.Bind();
		IBO = &(IndexBuffer(IBO_SIZE));
		for (int i = 0; i < MAX_SHAPES; i++)
		{
			GLCheck(glBufferSubData(GL_ARRAY_BUFFER, i* VERTEX_SIZE, SHAPE_SIZE, sizeof(shape)));
		}
		VBO = VertexBuffer(BUFFER_SIZE);
		VBO.Bind();
	

	}

	void BatchRenderer2D::Push(const Renderable2D * shape)
	{
		static int offset = 0;
		GLCheck(glBufferSubData(GL_ARRAY_BUFFER, offset, SHAPE_SIZE, shape))
	}

	void BatchRenderer2D::Flush()
	{
		glDrawArrays(GL_TRIANGLES, 0, IBO_SIZE);
	}

	BatchRenderer2D::BatchRenderer2D(const int MAX_SHAPES, unsigned int VERTEX_SIZE)
		:MAX_SHAPES(MAX_SHAPES),
		VERTEX_SIZE(VERTEX_SIZE)
	{

	}

	void BatchRenderer2D::Push(const Renderable2D* shape)
	{
	}
}