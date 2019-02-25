#include "Texture.h"
#include "pch.h"
#include "vendor/stb_image/stb_image.h"



namespace graphics
{

	std::map<std::string, unsigned int> Texture::texUnitMap;

	Texture::Texture(const std::string& path)
		:id(0),
		texUnit(0),
		filePath(path),
		localBuffer(nullptr),
		width(0),
		height(0),
		numColourChannels(0)

	{

		auto textureCache = texUnitMap.find(path);
		if (textureCache == texUnitMap.end())
		{
			
			LoadTexture(path);
			GLCheck(glGenTextures(1, &id));
			GLCheck(glBindTexture(GL_TEXTURE_2D, id));

			SetTextureSettings();
			
			GLCheck(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
			GLCheck(glGenerateMipmap(GL_TEXTURE_2D));
			GLCheck(glBindTexture(GL_TEXTURE_2D, id));

			if (localBuffer) {
				stbi_image_free(localBuffer);
				HP_SUCCESS("Successfully loaded texture from data path: ", path);
			}
			else
				HP_ERROR("Failed to load texture data from path: ", path);
		}

		else
		{
			texUnit = textureCache->second;
		}
	}


	void Texture::Delete()
	{
		GLCheck(glDeleteTextures(1, &id));
	}

	void Texture::Bind(unsigned int unit /* = 1 */)
	{
		texUnitMap.insert(std::pair(filePath, unit));
		texUnit = unit;

		GLCheck(glActiveTexture(GL_TEXTURE0 + unit));
		GLCheck(glBindTexture(GL_TEXTURE_2D, id));
	}

	void Texture::Unbind() const
	{
		GLCheck(glBindTexture(GL_TEXTURE_2D, 0));
	}

	void Texture::SetTextureSettings()
	{
		GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	}

	void Texture::LoadTexture(const std::string & path)
	{
		stbi_set_flip_vertically_on_load(1);
		localBuffer = stbi_load(path.c_str(), &width, &height, &numColourChannels, 4);
	}
}