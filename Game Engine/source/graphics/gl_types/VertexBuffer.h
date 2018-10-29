#pragma once
#include "debug/GLDebug.h"
#include <vector>
#include <tuple>

namespace graphics {
	class VertexBuffer
	{
	public:
		VertexBuffer() = default;
		VertexBuffer(const void* vertices, const unsigned int size); //Size of vertices array (in bytes)
		void Delete();
		void Bind() const;
		void Unbind() const;
		void PushLayout(unsigned int layoutSize, unsigned int type, bool normalized = false);
		inline auto GetLayout() const { return vbLayout; };
		inline unsigned int GetStride() const { return stride; };
		static unsigned int GetSizeOfType(unsigned int type);
	private:
		std::vector<std::tuple<unsigned int, unsigned int, bool>> vbLayout;
		unsigned int id;
		unsigned int stride = 0;

	}; 
}