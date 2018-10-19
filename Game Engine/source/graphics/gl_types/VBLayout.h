#pragma once
#include "GL/glew.h"
#include <vector>

struct VBElements
{
	int size; // size variable shows dimensions of vector
	unsigned int type;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type) {
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:   return 4;
		case GL_UNSIGNED_BYTE:  return 1;
		}
		return -1;
	}
};


class VBLayout
{
private:
	std::vector<VBElements> vbe;
	unsigned int stride;

public:
	VBLayout()
	:stride(0)
	{};

	template <typename T>
	void Set(int size)
	{
		static_assert(false);
	}

	template<>
	void Set<float>(int size)
	{
		vbe.push_back({ size, GL_FLOAT, GL_FALSE });
		stride += size * VBElements::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Set<unsigned int >(int size)
	{
		vbe.push_back({ size, GL_UNSIGNED_INT, GL_FALSE });
		stride += size * VBElements::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Set<unsigned char>(int size)
	{
		vbe.push_back({size, GL_UNSIGNED_BYTE, GL_FALSE});
		stride += size * VBElements::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VBElements>& GetElements() const{ return vbe; };
	inline unsigned int GetStride() const { return stride; };
};

