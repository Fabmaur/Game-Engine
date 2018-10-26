#pragma once
#include "maths/Vector.h"
#include "graphics/renderer/Texture.h"

namespace graphics {
	struct Material
	{
		Material() = default;
		Material(maths::vec3f ambient, maths::vec3f diffuse, maths::vec3f specular, maths::vec4f colour, float shininess)
			:ambient(ambient),
			diffuse(diffuse),
			specular(specular),
			shininess(shininess),
			colour(colour)
		{};

		maths::vec3f ambient;
		maths::vec3f diffuse;
		maths::vec3f specular;
		maths::vec4f colour;

		float shininess;

	};
}