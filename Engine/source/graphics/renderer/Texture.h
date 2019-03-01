#pragma once
#include <iostream>
#include <map>
#include <ft2build.h>
#include FT_FREETYPE_H  

namespace graphics
{
	/*The texture class loads an image file and creates a texture
	from it which can then be overlayed over an object. The texture
	must be bound if it is to be used.*/

	class Texture
	{
	public:
		Texture() = default;
		Texture(const std::string& path);
		Texture(FT_Face& font);
		void Delete();
		void Bind(); 
		void Unbind();
		void GenFontTexture(FT_Face& font);
		inline int GetWidth() const { return width; };
		inline int GetHeight() const { return height; };
		inline unsigned int GetTUID() const { return TUID; };

	private:
		void SetTextureSettings();
		void LoadTexture(const std::string& path);
		void GenTexture();

	private:
		unsigned int TUID; // Texture unit ID
		const std::string filePath;
		unsigned char* localBuffer;
		int width, height, numColourChannels;
		static std::map<std::string, unsigned int> texUnitMap;
	};
}

