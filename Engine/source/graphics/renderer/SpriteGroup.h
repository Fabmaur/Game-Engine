#pragma once
#include <vector>
#include "maths/Matrix4.h"
#include "Renderer2D.h"
#include "graphics/renderer/Renderable2D.h"

namespace graphics
{
	class SpriteGroup
	{
	public:
		SpriteGroup(const maths::mat4f& trans);
		void Push(Renderable2D* renderable);
		inline std::vector<Renderable2D*> GetRenderables() const { return renderables; }
	private:
		std::vector<Renderable2D*> renderables;
		maths::mat4f transMat;
	};
}
