#pragma once
#include "debug/GLDebug.h"
#include <vector>
#include <tuple>



namespace graphics
{
	/*Vertex Buffer class stores the vertex attributes of a renderable object
	e.g. position coords, texture coords in a vector of vbLayouts. An opengl VBO
	is also created which stores the vertex data that is sent of to the vertex shader
	in the graphics pipeline.*/

	class VertexBuffer
	{
	public:
		//layout size describes the dimension of the vertex attribute. e.g. position cords are 3D so layoutSize = 3
		//glType refers to the vertix attributes type such as a GLFloat
		VertexBuffer() = default;
		VertexBuffer(const void* verticesArray, const unsigned int sizeInBytes);
		VertexBuffer(const unsigned int bufferSize); // Maximum buffer size in bytes
		void Delete();
		void Bind() const;
		void Unbind() const;
		void PushLayout(unsigned int layoutSize, unsigned int glType, bool normalized = false);
		inline auto GetLayout() const { return vbLayout; };
		inline unsigned int GetStride() const { return stride; };
		static unsigned int GetSizeOfType(unsigned int type);
	private:
								//layoutSize  glType	  normalized
		std::vector<std::tuple<unsigned int, unsigned int, bool>> vbLayout;
		unsigned int id;
		//Stride Specifies the bytes between 2 vertices
		unsigned int stride = 0;

	}; 
}