#pragma once

#include "maths/Vector.h"

namespace graphics
{
	struct Triangle
	{
		static constexpr float vertices[] =
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		static constexpr float texVertices[] = 
		{
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.0f,  0.5f, 0.0f,	0.5f, 1.0f
		};

		static constexpr unsigned int id = 0;

		static constexpr float texCoords[] = 
		{
			0.0f, 0.0f,  // lower left corner  
			1.0f, 0.0f,  // lower right corner
			0.5f, 1.0f   // top center corner
		};

	};


}