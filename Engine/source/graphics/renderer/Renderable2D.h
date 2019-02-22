#pragma once
#include "maths/Vector.h"
#include "maths/Matrix2.h"

/* Base class for all 2D brenderables*/
namespace graphics
{
	
	struct Vertex
	{
		maths::vec3f pos;
		maths::mat2f TexCoords;
		float TUID;
		maths::vec4f colour;
	};
	
	class Renderable2D
	{
	public:
		inline maths::vec3f GetPos() const { return pos; }
		inline maths::vec2f GetSize() const { return size; }
		inline maths::vec4f GetColour() const { return colour; }
	
	protected:
		Renderable2D(maths::vec3f pos, maths::vec2f size, maths::vec4f colour)
			:pos(pos),
			size(size),
			colour(colour)
		{}
		
	private:
		maths::vec3f pos;
		maths::vec2f size;
		maths::vec4f colour;

	};
}