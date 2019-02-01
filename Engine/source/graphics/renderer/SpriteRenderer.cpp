#include "pch.h"
#include "SpriteRenderer.h"

namespace graphics
{

	void SpriteRenderer::Push(const Renderable2D* sprite)
	{
		spriteQueue.push_back((Sprite*)sprite);
	}

	void SpriteRenderer::RenderAndPop()
	{
		while (!spriteQueue.empty())
		{
			const Sprite* curSprite = spriteQueue.front();
			curSprite->GetTexture().Bind();
			curSprite->GetShader().Bind();
			curSprite->GetVAO().Bind();
			
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			curSprite->GetVAO().Unbind();
			curSprite->GetShader().Unbind();
			curSprite->GetTexture().Unbind();
	   	 	spriteQueue.pop_front();
		}
	}
	void SpriteRenderer::DrawSquare(graphics::Shader & shader, maths::vec3f pos, maths::vec3f size)
	{
		const float vertices[]
		{
			//Position						
			pos.x, pos.y - size.y, pos.z, 		   			//bottom left
			pos.x, pos.y, pos.z,							//top left
			pos.x + size.x, pos.y , pos.z,		   			//top right
			pos.x + size.x, pos.y - size.y, pos.z			//bottom right
		};


		VertexBuffer VBO(vertices, sizeof(vertices));
		VBO.PushLayout(3, GL_FLOAT);
		VertexArray VAO;
		VAO.SetVertexAttribArray(VBO);
		VAO.Bind();
		shader.Bind();
		GLCheck(glDrawArrays(GL_TRIANGLES, 0, 6));
		shader.Unbind();
		VAO.Unbind();
		VBO.Unbind();
	}
	void SpriteRenderer::DrawTriangle(graphics::Shader & shader, maths::vec3f pos1, maths::vec3f pos2, maths::vec3f pos3)
	{

		const float vertices[]
		{
			//Position
			pos1.x, pos2.y, pos1.z, 
			pos2.x, pos2.y, pos2.z,
			pos3.x, pos2.y, pos3.z
		};

		VertexBuffer VBO(vertices, sizeof(vertices));
		VBO.PushLayout(3, GL_FLOAT);
		VertexArray VAO;
		VAO.SetVertexAttribArray(VBO);
		VAO.Bind();
		shader.Bind();
		GLCheck(glDrawArrays(GL_TRIANGLES, 0, 3));
		shader.Unbind();
		VAO.Unbind();
		VBO.Unbind();
	}
	void SpriteRenderer::DrawLine(maths::vec3f pos1, maths::vec3f pos2)
	{
		const float vertices[]
		{
			//Position
			pos1.x, pos2.y, pos1.z,
			pos2.x, pos2.y, pos2.z
		};
		VertexBuffer VBO(vertices, sizeof(vertices));
		VBO.PushLayout(3, GL_FLOAT);
		VertexArray VAO;
		VAO.SetVertexAttribArray(VBO);
		VAO.Bind();
		Shader shader("resources/Default.shader");
		shader.Bind();
		GLCheck(glDrawArrays(GL_LINES, 0, 2));
		shader.Unbind();
		VAO.Unbind();
		VBO.Unbind();

	}
	void SpriteRenderer::DrawShape(void * vertices, unsigned int vertexNum, graphics::Shader& shader)
	{
		VertexBuffer VBO(vertices, vertexNum);
		VBO.PushLayout(3, GL_FLOAT);
		VertexArray VAO;
		VAO.SetVertexAttribArray(VBO);
		VAO.Bind();
		shader.Bind();
		GLCheck(glDrawArrays(GL_LINES, 0, vertexNum));
		shader.Unbind();
		VAO.Unbind();
		VBO.Unbind();
	}
	void SpriteRenderer::DrawCircle(const graphics::Shader & shader, const float radius)
	{
	}
}