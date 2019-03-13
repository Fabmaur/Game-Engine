#include "pch.h"
#include "Mesh.h"

namespace graphics
{
	Mesh::Mesh(std::vector<float>& vertices, std::vector<unsigned int>& indices)
		:Renderable3D(vertices, indices)
	{
		VertexBuffer VBO(vertices, size(vertices) * sizeof(float));

		VBO.PushLayout(3, GL_FLOAT);

		IndexBuffer IBO(indices);

		VAO.SetVertexAttribArray(VBO);
		VAO.BindIBO(IBO);
	}

	void Mesh::Draw(Shader& shader)
	{
		VAO.Bind();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		VAO.Unbind();
		
	}
}