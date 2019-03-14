#pragma once

#include <functional>

/* Holds elements of all the different events defined by 
the engine.*/
enum class Type
{
	MouseBtnPressed, MouseBtnReleased, MouseMoved,
	KeyPressed, KeyReleased,
	WindowResized
};

class EventMessage
{
	/* Base class of events. This enables any event in the engine to be 
	referenced as an EventMessage using polymorphism.*/
public:
	/* Used if a layer has handled an event and doesn't want it propogating 
	to other layers. */
	bool handled = false;
	Type type; // Holds the type that the event is


	/* Checks if an event is a certain type and if it is then it runs
	the function taken in as the argument. */
	template <typename Event>
	void ifIs(std::function<void(Event&)> func)
	{
		if ((*this).type == Event::GetType())
			func(*static_cast<Event*>(this));
			
	}

	/*Event classes derived from EventMessage 
	function must include static inline function GetType()*/
};