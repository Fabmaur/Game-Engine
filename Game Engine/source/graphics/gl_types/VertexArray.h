#pragma once
#include "VertexBuffer.h"
#include "VBLayout.h"
#include "debug/GLDebug.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void Bind() const;
	void Unbind() const;
	void Set(const VertexBuffer& vb , const VBLayout& vbl);

private:
	unsigned int id;
	unsigned int stride;

};