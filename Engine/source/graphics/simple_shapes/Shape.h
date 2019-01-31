#pragma once
#include "graphics/renderer/Renderable2D.h"
#include "maths/Vector.h"


namespace graphics
{
	struct VertexInfo
	{
		maths::vec3f pos;
		maths::vec4f colour;
	};

	class Rect : public Renderable2D
	{
	public:
		Rect(maths::vec3f pos, maths::vec2f size, maths::vec4f colour)
			:pos(pos),
			size(size),
			colour(colour) {}
		inline maths::vec3f& GetPos() const { return pos; }
		inline maths::vec2f& GetSize() const { return size; }
		inline maths::vec4f& GetColour() const { return colour; }
	private:
		maths::vec3f& pos;
		maths::vec2f& size;
		maths::vec4f& colour;
	};
}