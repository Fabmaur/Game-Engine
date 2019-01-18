#pragma once
#include <iostream>
#include "debug/GLDebug.h"
#include "GL/glew.h"
#include "vendor/stb_image/stb_image.h"


class Texture
{
public:
	Texture(const std::string path);
	void Delete();
	void Bind(unsigned int slot = 0) const;
	void Unbind() const;
	inline int GetWidth() const { return width; };
	inline int GetHeight() const { return height; };

private:
	unsigned int id;
	std::string filePath;
	unsigned char* localBuffer;
	int width, height, BPP;
};
