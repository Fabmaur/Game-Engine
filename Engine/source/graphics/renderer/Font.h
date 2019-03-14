#pragma once
#include <ft2build.h>

#include FT_FREETYPE_H 
namespace graphics
{
	struct Glyph
	{
		unsigned int TUID;      // ID of glyph texture
		maths::vec2f size;      // Size of glyph
		maths::vec2f bearing;   // Offset from base to top of glyph
		int advance;			// Offset to advance to next glyph
	};

	class Font
	{
	public:
		Font() = default;
		Font(FT_Library& ft, const std::string& fontPath);
		void SetSize(int size);
		Glyph& GetGlyph(char c);
		FT_Face& GetFace() { return font; };

	private:
		void GenGlyphs(FT_Face& font);

	private:
		FT_Face font;
		std::map<char, Glyph> characters; // Map of characters glyphs to chars
	}; 

}