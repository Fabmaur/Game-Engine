#include "SpriteRenderer.h"

using namespace graphics;

graphics::SpriteRenderer::SpriteRenderer(const Shader& shader)
	:shader(shader)
{
	IBO = IndexBuffer(Square::indices, 6);
}

void SpriteRenderer::Enqueue(const Sprite& sprite)
{
	renderObjects.emplace(sprite);
}

void graphics::SpriteRenderer::Dequeue()
{
	IBO.Bind();
	shader.Bind();
	while (!renderObjects.empty())
	{
		shader.SetUniformMaterial("Material", renderObjects.front().GetMaterial());
		GLCall(glBindVertexArray(renderObjects.front().GetID()));
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
	}
}
