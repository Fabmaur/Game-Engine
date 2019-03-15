#pragma once
#include "Renderable3D.h"
#include "graphics/gl_types/VertexArray.h"


namespace graphics
{
	class Mesh: public Renderable3D
	{
	public:
		Mesh() = default;
		//Constructor for user defined vertices
		Mesh(std::vector<float>& vertices, std::vector<unsigned int>& indices);
		// Constructor for mesh
		Mesh(const std::string& filename);
		void Draw(Shader& shader);

	private:
		// Used to split strings with spaces to vector of strings
		std::vector<std::string> Split(const std::string& string, char splitCharacter);

		// Used to sort the vertex data and push it to the vertex vector
		void SortAndPushVertex(std::vector<std::string>& vertex,
							   std::vector<maths::vec3f>& pos, 
							   std::vector<maths::vec2f>& texPos, 
							   std::vector<maths::vec3f>& normal);
	

	private:
		VertexArray VAO;
	};
}