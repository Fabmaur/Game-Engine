#pragma once
#include "Renderable3D.h"
#include "graphics/gl_types/VertexArray.h"


namespace graphics
{
	class Mesh: public Renderable3D
	{
	public:
		Mesh() = default;
		Mesh(std::vector<float>& vertices, std::vector<unsigned int>& indices);
		void Draw(Shader& shader);

	private:
		VertexArray VAO;
	};
}