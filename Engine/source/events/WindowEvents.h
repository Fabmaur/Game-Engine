#pragma once
#include "EventMessage.h"

class WindowResize : public EventMessage
{
public:
	WindowResize(int width, int height)
		:width(width), height(height) {}
	
	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }
private:
	int width, height;

};