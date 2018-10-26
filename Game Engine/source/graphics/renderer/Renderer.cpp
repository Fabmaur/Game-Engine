#include "Renderer.h"
#include <assert.h>

using namespace graphics;

void Renderer::CreateShape(unsigned int shapeID)
{

	switch (shapeID)
	{
	case graphics::Triangle::id:
	{
		VertexBuffer VBO(Triangle::vertices, sizeof(Triangle::vertices));
		VBO.PushLayout(3, GL_FLOAT);

		VertexArray VAO;
		VAO.SetInOne(VBO);
		VAO.Unbind();

		renderObjects.push_back(VAO.GetId());
		break;
	}

	case graphics::Square::id:
		VertexBuffer VBO(Square::vertices, sizeof(Square::vertices));
		VBO.PushLayout(3, GL_FLOAT);

		VertexArray VAO;
		VAO.SetInOne(VBO);

		VAO.Bind();

		IndexBuffer EBO(Square::indices, sizeof(Square::indices));
		EBO.Bind();
		VAO.Unbind();
		std::cout << VAO.GetId() << std::endl;
		renderObjects.push_back(VAO.GetId());
		break;
	}
}

void Renderer::SetShader(const char* string)
{
	Shader shader(string);
	shader.Bind();
}

void Renderer::Draw()
{
	// TODO: Implement function
}

void graphics::Renderer::DrawSquare()
{
	GLCall(glBindVertexArray(renderObjects.front()));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void graphics::Renderer::DrawTriangle()
{
	GLCall(glBindVertexArray(renderObjects.front()));
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));
}
