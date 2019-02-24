#include "Texture.h"
#include "pch.h"
#include "vendor/stb_image/stb_image.h"
#include <map>


namespace graphics
{

	std::map<std::string, unsigned int> Texture::texMap;

	Texture::Texture()
		:id(0),
		filePath("Undefined"),
		localBuffer(nullptr),
		width(0),
		height(0),
		numColourChannels(0)
	{ 
		if (texMap.find("Undefined") != texMap.end())
		{
			texMap.insert("Undefined", 0);
		}
	}

	Texture::Texture(const std::string& path)
		:id(0),
		filePath(path),
		localBuffer(nullptr),
		width(0),
		height(0),
		numColourChannels(0)

	{

		if (texMap.find(path) == texMap.end())
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

		}
	}


	void Texture::Delete()
	{
		if (filePath != "Undefined")
		GLCheck(glDeleteTextures(1, &id));
	}

	void Texture::Bind(unsigned int slot = 0) const
	{
		if (filePath != "Undefined")
		{
			GLCheck(glActiveTexture(GL_TEXTURE0 + slot));
			GLCheck(glBindTexture(GL_TEXTURE_2D, id));
		}
	}

	void Texture::Unbind() const
	{
		if (filePath != "Undefined")
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