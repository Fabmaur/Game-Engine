#pragma once
#include "Renderable3D.h"


namespace graphics
{
	class Mesh: public Renderable3D
	{
	public:
		Mesh(std::vector<float>& vertices, std::vector<unsigned int>& indices);
		void Draw(Shader& shader, maths::mat4f& mvp, maths::vec3f colour);

	private:
		VertexArray VAO;
	};
}