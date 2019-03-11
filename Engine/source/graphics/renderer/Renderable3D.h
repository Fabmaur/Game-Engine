#pragma once
#include "maths/Vector.h"
#include <vector>


namespace graphics
{
	struct MeshVertex
	{
		maths::vec3f pos;
		maths::vec3f normal;
		maths::vec3f texCoords;
		maths::vec4f colour;
	};

	class Renderable3D
	{
	public:
		Renderable3D() = default;
		Renderable3D(std::vector<float>& vertices, std::vector<unsigned int>& indices)
			:vertices(vertices),
			indices(indices)
		{}

	protected:
		std::vector<float> vertices;
		std::vector<unsigned int> indices;
	};
}