#pragma once
#include "Renderable2D.h"

namespace graphics
{
	/*Base renderer class which specifies functions that
	should be implemented by the derived renderer classes.*/
	class Renderer2D
	{
	public:
		virtual void Push(const Renderable2D* sprite) = 0;
		virtual void RenderAndPop() = 0;

	};
}