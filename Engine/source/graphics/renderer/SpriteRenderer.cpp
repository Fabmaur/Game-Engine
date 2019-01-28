#include "pch.h"
#include "SpriteRenderer.h"

namespace graphics
{

	void SpriteRenderer::Push(const Sprite* sprite)
	{
		spriteQueue.push_back(sprite);
	}

	void SpriteRenderer::Flush()
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
}