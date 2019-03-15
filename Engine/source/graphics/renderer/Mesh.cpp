#include "pch.h"
#include "Mesh.h"
#include <iostream>
#include <iterator>

namespace graphics
{
	Mesh::Mesh(std::vector<float>& vertices, std::vector<unsigned int>& indices)
		:Renderable3D(vertices, indices)
	{

		// Creates Vertex and Index buffer for cube with position and Texture
		VertexBuffer VBO(vertices);

		VBO.PushLayout(3, GL_FLOAT);
		VBO.PushLayout(2, GL_FLOAT);

		IndexBuffer IBO(indices);

		VAO.SetVertexAttribArray(VBO);
		VAO.BindIBO(IBO);
	}

	Mesh::Mesh(const std::string& filename)
	{
		// Checking to see if the file is the correct type
		if (!filename.find("obj"))
			HP_FATAL("ERROR: File type not supported");
		
		std::ifstream in(filename);
		if (!in)
			HP_FATAL("ERROR: File could not open");
		
		std::string line;
		std::vector<maths::vec3f> pos;
		std::vector<maths::vec2f> texPos;
		std::vector<maths::vec3f> normals;

		while (std::getline(in, line)) // Going from start to end of file
		{
			if (line[0] == 'v' && (line[1] == ' '))
			{
				line.erase(0, 2); // erasing v and space from line
				std::vector<std::string> data = Split(line, ' ');
				// Pushing vertex data to pos list
				pos.push_back({ (float)atof(data[0].c_str()), 
									(float)atof(data[1].c_str()), 
									(float)atof(data[2].c_str())});
			}
			else if ((line[0] == 'v') && (line[1] == 't'))
			{
				line.erase(0, 3); // erasing vt and space from line
				std::vector<std::string> data = Split(line, ' ');
				// Pushing vertex data to texPos list
				texPos.push_back({ (float)atof(data[0].c_str()),
									(float)atof(data[1].c_str())});
			}
			else if ((line[0] == 'v') && (line[1] == 'n'))
			{
				line.erase(0, 3); // erasing vn and space from line
				std::vector<std::string> data = Split(line, ' ');
				// Pushing vertex data to normals list
				normals.push_back({ (float)atof(data[0].c_str()),
									(float)atof(data[1].c_str()),
									(float)atof(data[2].c_str())});
			}
			else if (line[0] == 'f')
			{
				line.erase(0, 2); // erasing f and space from line
				// Parsing line
				std::vector<std::string> vertexData = Split(line, ' ');
				std::vector<std::string> vertex1 = Split(vertexData[0], '/');
				std::vector<std::string> vertex2 = Split(vertexData[1], '/');
				std::vector<std::string> vertex3 = Split(vertexData[2], '/');
				// Sorting the vertex data with the face information and sending 
				//it to vertices list
				SortAndPushVertex(vertex1, pos, texPos, normals);
				SortAndPushVertex(vertex2, pos, texPos, normals);
				SortAndPushVertex(vertex3, pos, texPos, normals);
			}
		}
		VertexBuffer VBO(vertices);
		VBO.PushLayout(3, GL_FLOAT);
		VBO.PushLayout(2, GL_FLOAT);
		VBO.PushLayout(3, GL_FLOAT);

		VAO.SetVertexAttribArray(VBO);
		IndexBuffer IBO(indices);
		VAO.BindIBO(IBO);
	}

	void Mesh::Draw(Shader& shader)
	{
		VAO.Bind();
		glDrawElements(GL_TRIANGLES, size(indices), GL_UNSIGNED_INT, 0);
		VAO.Unbind();
		
	}

	std::vector<std::string> Mesh::Split(const std::string& string, char splitCharacter)
	{
		std::vector<std::string> data;
		std::string dataPoint;
		std::istringstream iss(string); 
		while (std::getline(iss, dataPoint, splitCharacter))
		{
			data.push_back(dataPoint);
		}
		return data;

	}

	void Mesh::SortAndPushVertex( std::vector<std::string>& vertex,
								  std::vector<maths::vec3f>& pos,
								  std::vector<maths::vec2f>& texPos,
								  std::vector<maths::vec3f>& normal)
	{
		// Vertices 

		int curPos = atof(vertex[0].c_str()) - 1;
		vertices.push_back(pos[curPos].x);
		vertices.push_back(pos[curPos].y);
		vertices.push_back(pos[curPos].z);

		//indices
		indices.push_back(curPos);

		// Texture Coordinates
		int curTexPos = atof(vertex[1].c_str()) - 1;
		vertices.push_back(texPos[curTexPos].x);
		vertices.push_back(1.0f - texPos[curTexPos].y);

		// Normals
		int curNormalPos = atof(vertex[2].c_str()) - 1;
		vertices.push_back(normal[curNormalPos].x);
		vertices.push_back(normal[curNormalPos].y);
		vertices.push_back(normal[curNormalPos].z);
	}
}