#pragma once

#include "graphics/renderer/Material.h"
#include "maths/Vector.h"

namespace graphics
{
	struct Triangle
	{
		static constexpr float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
		};

		Material M;
		static constexpr unsigned int id = 0;
	};

}