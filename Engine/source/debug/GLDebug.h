#pragma once

#include "ProjectLog.h"
#include "GL/glew.h"


// Macros will only be defined if DEBUG macro is set
#ifdef DEBUG

// If statement x is false then stop program and write erro message
#define HP_ASSERT(x, ...){ if(!(x)){\
							 HP_FATAL(__VA_ARGS__);\
							 __debugbreak();}}

#define GAME_ASSERT(x, ...){ if(!(x)){\
								GAME_FATAL(__VA_ARGS__);\
								__debugbreak();}}

#define ASSERT(x) { if(!(x)) __debugbreak();}


//Clear past error flags and check for any new errors
#define GLCheck(x) debug::ClearError();\
    x;\
    ASSERT(debug::LogCall(#x, __FILE__, __LINE__))
	
#else
#define GLCheck(x) x
#define HP_ASSERT(x)
#define GAME_ASSERT(x)
#define ASSERT(x)
#endif

namespace debug
{
	/*Used to debug*/

	static void ClearError() // Clears the previous error flags
	{
		while (glGetError());
	}
	static bool LogCall(const char* function, const char* file, int line)
	{
		const int totalFlagCount{ 7 };
		int flagNum{ 0 };

		//Loops through all the error flags and print outs if there is an error
		while (GLenum errorCode = glGetError())
		{
			
			std::string error{""};
			switch (errorCode)
			{
			case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
			case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
			case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
			case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
			case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
			case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
			case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
			}
			flagNum++;
			if(flagNum ==  totalFlagCount)
				return false;
			HP_ERROR("[OpenGL Error]", error, " Function ", function, " ", file, ":", line);
		}
		return true;
	}
}