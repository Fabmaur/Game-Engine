#include "pch.h"
#include "SpriteGroup.h"

namespace graphics
{
	SpriteGroup::SpriteGroup(const maths::mat4f& trans)
		:transMat(trans) 
	{}

	void SpriteGroup::Push(Renderable2D* renderable)
	{
		renderables.push_back(renderable);
	}
}