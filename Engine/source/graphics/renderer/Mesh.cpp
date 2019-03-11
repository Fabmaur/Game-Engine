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

	void Mesh::Draw(Shader& shader, maths::mat4f& mvp, maths::vec3f colour)
	{
		VAO.Bind();
		shader.Bind();
		shader.SetUniformMat4f("mvp", mvp);
		shader.SetUniform3v("colour", colour);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		shader.Unbind();
	}
}