#pragma once
#include "maths/Vector.h"
#include "maths/Matrix2.h"

/* Base class for all 2D brenderables*/
namespace graphics
{
	// Vertex Data a batch sprite holds
	struct Vertex
	{
		maths::vec3f pos;
		maths::vec2f TexCoords;
		float TUID;
		maths::vec4f colour;
	};
	
	class Renderable2D
	{
		/* Based class for a 2D renderable object*/
	public:
		inline maths::vec3f GetPos() const { return pos; }
		inline maths::vec2f GetSize() const { return size; }
		inline maths::vec2f GetTexPos() const { return texPos; }
		inline maths::vec2f GetTexSize() const { return texSize; }
		inline maths::vec4f GetColour() const { return colour; }
	
	protected:
		Renderable2D(maths::vec3f pos, maths::vec2f size, 
			maths::vec2f texPos, maths::vec2f texSize, maths::vec4f colour)
			:pos(pos),
			size(size),
			colour(colour),
			texPos(texPos),
			texSize(texSize)
		{}

		Renderable2D(maths::vec3f pos, maths::vec2f size, maths::vec4f colour)
			:Renderable2D(pos, size, { 0.0f, 0.0f }, { 1.0f, 1.0f, }, colour)
		{}

		
	private:
		maths::vec3f pos;
		maths::vec2f size;
		maths::vec2f texPos;
		maths::vec2f texSize;
		maths::vec4f colour;

	};
}