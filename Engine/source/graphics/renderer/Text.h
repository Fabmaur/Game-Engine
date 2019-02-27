#pragma once
#include "maths/Vector.h"

#include <ft2build.h>
#define FT2BUILD_H_
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>


namespace graphics
{
	struct Glyph
	{
		unsigned int TUID;      // ID handle of the glyph texture
		maths::vec2f size;      // Size of glyph
		maths::vec2f bearing;   // Offset from baseline to left/top of glyph
		int advance;			// Horizontal offset to advance to next glyph
	};

	class Text
	{
	public:
		Text();
	private:
		FT_Library ft;
	};
	
}