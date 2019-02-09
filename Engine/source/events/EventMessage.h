#pragma once

#include <functional>

enum class Type
{
	MouseBtnPressed, MouseBtnReleased, MouseMoved,
	KeyPressed, KeyReleased,
	WindowResized
};

class EventMessage
{
public:
	bool handled = false;
	Type type;

	template <typename Event>
	void ifIs(std::function<void(Event&)> func)
	{
		if ((*this).type == Event::GetType())
			func(*static_cast<Event*>(this));
			
	}
	/*Event classes derived from EventMessage 
	function must include static inline function GetType()*/
};