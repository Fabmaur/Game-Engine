#include "pch.h"
#include "BatchRenderer2D.h"
#include "debug/GLDebug.h"
#include "graphics/simple_shapes/Shape.h"


namespace graphics
{

	BatchRenderer2D::BatchRenderer2D(const int MAX_SHAPES)
		:MAX_SHAPES(MAX_SHAPES),
		VERTEX_SIZE(sizeof(graphics::VertexInfo)),
		SHAPE_SIZE(4 * sizeof(graphics::VertexInfo)),
		BUFFER_SIZE(4 * sizeof(graphics::VertexInfo) * MAX_SHAPES),
		IBO_SIZE(MAX_SHAPES * 6)
	{
		VAO.Bind();
		VBO = VertexBuffer(BUFFER_SIZE);
		VBO.PushLayout(3, GL_FLOAT); // Setting rect->GetPos()ition
		VBO.PushLayout(4, GL_FLOAT); // Setting colour
		VAO.SetVertexAttribArray(VBO);


		unsigned int* indices = new unsigned int[IBO_SIZE];

		int offset = 0;
		for (int i = 0; i < MAX_SHAPES; i += 6) // For every shape
		{
			indices[i] = offset;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;
			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset;
			offset += 4;
		}
		IndexBuffer IBO(indices, IBO_SIZE);
		VAO.BindIBO(IBO);
		VAO.Unbind();
		VBO.Bind();
		offset = 0;
	}

	void BatchRenderer2D::Push(const Renderable2D* shape)
	{

		Rect* rect = (Rect*)shape;

		const float x = rect->GetPos().x;
		const float y = rect->GetPos().y;
		const float z = rect->GetPos().z;
		const float sizeX = rect->GetSize().x;
		const float sizeY = rect->GetSize().y;
		const float r = rect->GetColour().x;
		const float g = rect->GetColour().y;
		const float b = rect->GetColour().z;
		const float a = rect->GetColour().w;

		const float vertices[]
		{
			//position				  Colour 
			x,		   y - sizeY, z, r, g, b, a,	//bottom left
			x,		   y,		  z, r, g, b, a,	//top left
			x + sizeX, y,		  z, r, g, b, a,	//top right
			x + sizeX, y - sizeY, z, r, g, b, a		//bottom right
		};
		GLCheck(glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(vertices), vertices));
		offset += 6;
	}

	void BatchRenderer2D::RenderAndPop()
	{
		VBO.Bind();
		VAO.Bind();
		glDrawElements(GL_TRIANGLES, IBO_SIZE, GL_UNSIGNED_INT,0);
		VAO.Unbind();
		offset = 0;
	}

}