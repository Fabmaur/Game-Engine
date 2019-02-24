#pragma once
#include <iostream>

namespace graphics
{
	/*The texture class loads an image file and creates a texture
	from it which can then be overlayed over an object. The texture
	must be bound if it is to be used.*/

	class Texture
	{
	public:
		Texture();
		Texture(const std::string& path);
		void Delete();
		void Bind(unsigned int slot = 0) const;
		void Unbind() const;
		inline int GetWidth() const { return width; };
		inline int GetHeight() const { return height; };

	private:
		void SetTextureSettings();
		void LoadTexture(const std::string& path);

	private:
		unsigned int id;
		const std::string& filePath;
		unsigned char* localBuffer;
		int width, height, numColourChannels;
		static std::map<std::string, unsigned int> texMap;
	};
}

