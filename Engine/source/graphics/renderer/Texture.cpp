#include "Texture.h"
#include "pch.h"
#include "vendor/stb_image/stb_image.h"

namespace graphics
{

	std::map<std::string, unsigned int> Texture::texUnitMap;

	Texture::Texture(const std::string& path)
		:TUID(0),
		filePath(path),
		localBuffer(nullptr),
		width(0),
		height(0),
		numColourChannels(0)
	{

		auto textureCache = texUnitMap.find(path);
		if (textureCache == texUnitMap.end())
		{
			
			GLCheck(glGenTextures(1, &TUID));
			GLCheck(glBindTexture(GL_TEXTURE_2D, TUID));
			texUnitMap.insert(std::pair(filePath, TUID));

			LoadTexture(path);
			SetTextureSettings();
			GenTexture();
			
			if (localBuffer) 
			{
				stbi_image_free(localBuffer);
				HP_SUCCESS("Successfully loaded texture from data path: ", path);
			}
			else
				HP_ERROR("Failed to load texture data from path: ", path);
		}

		else
		{
			TUID = textureCache->second;
		}
	}

	Texture::Texture(FT_Face& font)
	{
		GLCheck(glGenTextures(1, &TUID));
		GLCheck(glBindTexture(GL_TEXTURE_2D, TUID));

		SetTextureSettings();
		GenFontTexture(font);
		
	}


	void Texture::Delete()
	{
		GLCheck(glDeleteTextures(1, &TUID));
	}

	void Texture::Bind()
	{
		GLCheck(glActiveTexture(GL_TEXTURE0 + TUID));
		GLCheck(glBindTexture(GL_TEXTURE_2D, TUID));
	}

	void Texture::GenFontTexture(FT_Face& font)
	{
		GLCheck(glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			font->glyph->bitmap.width,
			font->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			font->glyph->bitmap.buffer
		));
	}

	void Texture::Unbind()
	{
		GLCheck(glBindTexture(GL_TEXTURE_2D, 0));
	}

	void Texture::SetTextureSettings()
	{
		GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	}

	void Texture::LoadTexture(const std::string& path)
	{
		stbi_set_flip_vertically_on_load(1);
		localBuffer = stbi_load(path.c_str(), &width, &height, &numColourChannels, 4);
	}
	void Texture::GenTexture()
	{
		GLCheck(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
		GLCheck(glGenerateMipmap(GL_TEXTURE_2D));
	}
}