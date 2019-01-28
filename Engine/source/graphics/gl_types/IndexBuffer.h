#pragma once

namespace graphics 
{
	/*Stores index data of vertices*/
	class IndexBuffer
	{
	public:
		IndexBuffer() = default;
		IndexBuffer(const void* indices, const unsigned int count); // Amount of indices is the count
		void Delete();
		void Bind() const;
		void Unbind() const;
		
		inline unsigned int GetCount() { return count; };

	private:
		const unsigned int count;
		unsigned int id;
	};
}
