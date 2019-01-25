#pragma once
#include "Sprite.h"

namespace graphics
{
	class Renderer2D
	{
	protected:
		virtual void Push(Sprite& sprite) = 0;
		virtual void Flush() = 0;

	};
}