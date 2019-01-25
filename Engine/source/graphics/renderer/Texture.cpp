#include "Texture.h"
#include "pch.h"
#include "vendor/stb_image/stb_image.h"


namespace graphics
{
	Texture::Texture(const std::string path)
		:id(0),
		filePath(path),
		localBuffer(nullptr),
		width(0),
		height(0),
		BPP(0)

	{
		stbi_set_flip_vertically_on_load(1);
		localBuffer = stbi_load(path.c_str(), &width, &height, &BPP, 4);

		GLCall(glGenTextures(1, &id));
		GLCall(glBindTexture(GL_TEXTURE_2D, id));


		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
		GLCall(glGenerateMipmap(GL_TEXTURE_2D));
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));

		if (localBuffer) {
			stbi_image_free(localBuffer);
			HP_SUCCESS("Successfully loaded texture from data path: ", path);
		}
		else
			HP_ERROR("Failed to load texture data from path: ", path);
	}


	void Texture::Delete()
	{
		GLCall(glDeleteTextures(1, &id));
	}

	void Texture::Bind(unsigned int slot) const
	{
		GLCall(glActiveTexture(GL_TEXTURE0 + slot));
		GLCall(glBindTexture(GL_TEXTURE_2D, id));
	}

	void Texture::Unbind() const
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}
}