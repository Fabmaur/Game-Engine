#pragma once
#include <vector>


namespace graphics 
{
	/*Stores index data of vertices*/
	class IndexBuffer
	{
	public:
		IndexBuffer() = default;
		IndexBuffer(const void* indices, const unsigned int count); // Amount of indices is the count
		IndexBuffer(std::vector<unsigned int>& indices);
		IndexBuffer(const unsigned int bufferSize); // Maximum buffer size in bytes
		void Delete();
		void Bind() const;
		void Unbind() const;
		inline unsigned int GetCount() const { return count; };

	private:
		unsigned int count;
		unsigned int id;
	};
}
