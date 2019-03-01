#include "pch.h"
#include "Text.h"
#include "Font.h"

namespace graphics
{



	Text::Text(const std::string& fontPath, std::string text)
		:text(text)
	{
		FT_Library aFt;
		if (FT_Init_FreeType(&aFt))
			HP_ERROR("ERROR::FREETYPE: Could not init FreeType Library");

		ft = aFt;
		SetFont(fontPath);
	}


	void Text::SetFont(const std::string & fontPath)
	{
		auto fontCache = fonts.find(fontPath);
		if (fontCache == fonts.end())
		{
			font = Font(ft, fontPath);
			fonts.insert(std::pair(fontPath, &font));
		}
		else
			font = *fontCache->second;
	}

	void Text::SetSize(Font& font, int size)
	{
		FT_Set_Pixel_Sizes(font.GetFace(), 0, size);
	}
	

}