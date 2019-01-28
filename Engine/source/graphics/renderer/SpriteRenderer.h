#pragma once
#include "Renderer2D.h"

#include "Sprite.h"
#include <deque>

namespace graphics
{
	class SpriteRenderer : public Renderer2D
	{
	public:
		void Push(Sprite& sprite)  override;
		void Flush()  override;

	private:
		std::deque<Sprite> spriteQueue;

	};
}
