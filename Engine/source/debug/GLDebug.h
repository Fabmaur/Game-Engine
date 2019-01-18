#pragma once

#include <iostream>
#include "GL/glew.h"

#ifdef DEBUG

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLDebug::ClearError();\
    x;\
    ASSERT(GLDebug::LogCall(#x, __FILE__, __LINE__))
	
#else
#define GLCall(x) x
#define ASSERT(x) x
#endif

namespace debug {

	static void ClearError() // Clears the previous error flags
	{
		while (glGetError());
	}
	static bool LogCall(const char* function, const char* file, int line)
	{
		while (GLenum error = glGetError())
		{
			std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << std::endl;
			return false;
		}
		return true;
	}
}