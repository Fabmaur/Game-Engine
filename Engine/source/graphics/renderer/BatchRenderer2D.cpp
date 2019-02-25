#include "pch.h"
#include "BatchRenderer2D.h"
#include "debug/GLDebug.h"


namespace graphics
{

	BatchRenderer2D::BatchRenderer2D(Shader& shader, const int MAX_SHAPES)
		:MAX_SHAPES(MAX_SHAPES),
		VERTEX_SIZE(sizeof(graphics::Vertex)),
		SHAPE_SIZE(4 * sizeof(graphics::Vertex)),
		BUFFER_SIZE(4 * sizeof(graphics::Vertex) * MAX_SHAPES),
		IBO_SIZE(MAX_SHAPES * 6)
	{
		int texUnitID[] = {
			0, 1, 2, 3, 4, 5, 6, 7, 8,
			9, 10, 11, 12, 13, 14, 15
		};

		shader.SetUniformiv("textures", 16, texUnitID);
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

	void BatchRenderer2D::Push(const Renderable2D* renderable)
	{

		BatchSprite* rect = (BatchSprite*)renderable;

		maths::vec3f pos = { rect->GetPos().x, rect->GetPos().y, rect->GetPos().z };
		pos = transMat.back().MultiplyByVec3f(pos);
		const float sizeX = rect->GetSize().x;
		const float sizeY = rect->GetSize().y;
		const float r = rect->GetColour().r;
		const float g = rect->GetColour().g;
		const float b = rect->GetColour().b;
		const float a = rect->GetColour().a;
		const unsigned int texUnit = rect->GetTexture() == nullptr ? 0 : rect->GetTexture()->GetTexUnitID();

		const float vertices[]
		{
			//position				  			   Texture Coords	TexUnit		Colour
			pos.x,		   pos.y - sizeY, pos.z,	0.0f, 0.0f,		texUnit,	r, g, b, a,		//bottom left
			pos.x,		   pos.y,		  pos.z,	0.0f, 1.0f,		texUnit,	r, g, b, a,		//top left
			pos.x + sizeX, pos.y,		  pos.z,	1.0f, 1.0f,		texUnit,	r, g, b, a,		//top right
			pos.x + sizeX, pos.y - sizeY, pos.z,	1.0f, 0.0f,		texUnit,	r, g, b, a		//bottom right
		};
		GLCheck(glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(vertices), vertices));
		offset += 6;
	}

	void BatchRenderer2D::RenderAndPop()
	{
		VAO.Bind();
		glDrawElements(GL_TRIANGLES, IBO_SIZE, GL_UNSIGNED_INT,0);
		VAO.Unbind();
		offset = 0;
	}

}