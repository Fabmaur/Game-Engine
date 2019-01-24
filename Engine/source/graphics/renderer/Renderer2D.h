#pragma once

class 2DRenderer
{
public:
	virtual void Push() = 0;
	virtual void Flush() = 0;

};