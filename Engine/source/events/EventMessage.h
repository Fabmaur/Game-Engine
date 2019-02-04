#pragma once

#include <functional>

enum class Type
{
	MouseBtnPressed, MouseBtnReleased, MouseMoved,
	KeyPressed, KeyReleased
};

class EventMessage
{
	bool handled;
};

class EventReciever
{
public:
	void onEvent(EventMessage& event, std::function<bool(void)> func)
	{
		func();
	}
};