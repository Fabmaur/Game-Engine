#pragma once
#include "Sprite.h"

namespace graphics
{
	/*Base renderer class which specifies functions that
	should be implemented by the derived renderer classes.*/
	class Renderer2D
	{
	protected:
		virtual void Push(const Sprite* sprite) = 0;
		virtual void Flush() = 0;

	};
}