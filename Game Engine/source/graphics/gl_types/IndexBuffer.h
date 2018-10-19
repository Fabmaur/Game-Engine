#pragma once

class IndexBuffer
{
public:
	IndexBuffer(const void* indices, const unsigned int count); // Amount of indexes is the count
	~IndexBuffer();
	void Bind() const;
	void Unbind() const;

private:
	unsigned int id;
};
