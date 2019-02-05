#pragma once

#include <functional>

enum class Type
{
	MouseBtnPressed, MouseBtnReleased, MouseMoved,
	KeyPressed, KeyReleased
};

class EventMessage
{
public:
	bool handled;
	Type type;
};