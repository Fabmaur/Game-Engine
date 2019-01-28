#include "pch.h"
#include "SpriteRenderer.h"

namespace graphics
{

	void SpriteRenderer::Push(Sprite& sprite)
	{
		spriteQueue.push_back(sprite);
	}

	void SpriteRenderer::Flush()
	{
		while (!spriteQueue.empty())
		{
			Sprite& curSprite = spriteQueue.front();
			curSprite.GetVAO().Bind();
			curSprite.GetShader().Bind();
			curSprite.GetShader().SetUniform1i("tex", 0);
			
			glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

			curSprite.GetVAO().Unbind();
			curSprite.GetShader().Unbind();
	   	 	spriteQueue.pop_front();
		}
	}
}