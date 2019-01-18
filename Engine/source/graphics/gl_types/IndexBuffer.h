#pragma once

namespace graphics {

	class IndexBuffer
	{
	public:
		IndexBuffer() = default;
		IndexBuffer(const void* indices, const unsigned int count); // Amount of indices is the count
		void Delete();
		void Bind() const;
		void Unbind() const;

	private:
		unsigned int id;
	};
}
