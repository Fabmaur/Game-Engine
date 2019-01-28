#pragma once
#include "Renderer2D.h"

#include "Sprite.h"
#include <deque>

namespace graphics
{
	/*Derived class of renderer - used to render sprites*/

	class SpriteRenderer : public Renderer2D
	{
	public:
		void Push(const Sprite* sprite)  override;
		void Flush()  override;

	private:
		std::deque<const Sprite*> spriteQueue;

	};
}
