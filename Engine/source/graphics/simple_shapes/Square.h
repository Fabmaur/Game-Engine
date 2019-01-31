#pragma once

#include "maths/Vector.h"

namespace graphics
{
	struct Rect
	{
		static constexpr float texVertices[] = {
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // top right
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f // top left 
		};


		static constexpr float vertices[] = {
			 0.5f,  0.5f, 0.0f,  // top right
			 0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left 
			};
		static constexpr unsigned int indices[] = {
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		};

		maths::vec3f colour;
		maths::vec2f pos;
		static constexpr unsigned int id = 2;

	};

}