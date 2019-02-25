#pragma once
#include <iostream>
#include <map>

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
		void Delete();
		void Bind(unsigned int unit = 1); //default texture unit ( for no texture ) is set to 0
		void Unbind() const;
		inline int GetWidth() const { return width; };
		inline int GetHeight() const { return height; };
		inline unsigned int GetID() const { return id; };
		inline unsigned int GetTexUnitID() const { return texUnit; };

	private:
		void SetTextureSettings();
		void LoadTexture(const std::string& path);

	private:
		unsigned int id;
		unsigned int texUnit;
		const std::string filePath;
		unsigned char* localBuffer;
		int width, height, numColourChannels;
		static std::map<std::string, unsigned int> texUnitMap;
	};
}

