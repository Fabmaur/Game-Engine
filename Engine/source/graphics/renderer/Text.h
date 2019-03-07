#pragma once
#include "maths/Vector.h"
#include <map>
#include "Font.h"

#include <ft2build.h>
#include FT_FREETYPE_H  

namespace graphics
{
	class Text
	{

	public:
		Text() = default;
		Text(const std::string& fontPath, std::string text);
		void Push(const std::string& atext) { text = atext; };
		void SetFont(const std::string& fontPath);
		void SetSize(Font& font, int size);
		Font GetFont() const { return font; };
		std::string GetTextStr() const { return text; };
	private:
		std::string text;
		FT_Library ft;
		Font font;
		std::map<std::string, Font*> fonts;
		
	};
	
}