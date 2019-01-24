#pragma once

#include "ProjectLog.h"
#include "GL/glew.h"

#ifdef DEBUG

#define HP_ASSERT(x, ...){ if(!(x)) {HP_FATAL(__VA_ARGS__); __debugbreak();}}
#define GAME_ASSERT(x, ...){ if(!(x)) {GAME_FATAL(__VA_ARGS__); __debugbreak();}}
#define ASSERT(x) { if(!(x)) __debugbreak();}
#define GLCall(x) debug::ClearError();\
    x;\
    ASSERT(debug::LogCall(#x, __FILE__, __LINE__))
	
#else
#define GLCall(x) x
#define HP_ASSERT(x)
#define GAME_ASSERT(x)
#define ASSERT(x)
#endif

namespace debug
{

	static void ClearError() // Clears the previous error flags
	{
		while (glGetError());
	}
	static bool LogCall(const char* function, const char* file, int line)
	{
		while (GLenum error = glGetError())
		{
			HP_ERROR("[OpenGL Error]Code: ", error , " Function ", function, " " , file, ":", line);
			return false;
		}
		return true;
	}
}