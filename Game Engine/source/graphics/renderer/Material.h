#pragma once
#include "maths/Vector.h"

namespace graphics {
	struct Material
	{
		Material() = default;

		maths::vec3f ambient;
		maths::vec3f diffuse;
		maths::vec3f specular;
		float shininess;

	};
}