#include "pch.h"
#include "Font.h"

namespace graphics
{
	Font::Font(FT_Library& ft, const std::string& fontPath)
	{
		if (FT_New_Face(ft, fontPath.c_str(), 0, &font))
			HP_ERROR("ERROR::FREETYPE: Failed to load font");
		else
			HP_SUCCESS("Successfully loaded font from data path: ", fontPath);
		
		SetSize(32);
		GenGlyphs(font);
	}

	void Font::SetSize(int size)
	{
		FT_Set_Pixel_Sizes(font, 0, size);
	}

	Glyph& Font::GetGlyph(char c)
	{
		return characters[c];
	}

	void Font::GenGlyphs(FT_Face& font)
	{
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		for (unsigned char c = 0; c < 128; c++)
		{

			if (FT_Load_Char(font, c, FT_LOAD_RENDER))
			{
				HP_ERROR("ERROR::FREETYTPE: Failed to load Glyph");
				continue;
			}
			Texture glyph(font);

			// Cache glyph in map
			Glyph character = 
			{
				glyph.GetTUID(),
				maths::vec2f(font->glyph->bitmap.width, font->glyph->bitmap.rows),
				maths::vec2f(font->glyph->bitmap_left, font->glyph->bitmap_top),
				font->glyph->advance.x
			};

			characters.insert(std::pair<char, Glyph>(c, character));
		}

		
	}

}
