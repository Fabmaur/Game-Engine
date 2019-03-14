#pragma once
#include "events/EventMessage.h"
#include "graphics/renderer/Layer.h"

namespace core
{
	/* Base class for any game which run on the engine.
	This is so that the engine can refer to any game 
	on the engine as a UserApplication type and 
	therefore use polymorphism to process the game. */

	class UserApplication
	{
	public:
		/* The event callback which is sent to the window
		class and called when an event takes place. */
		virtual void EventCallBack(EventMessage& event);
		std::function<void(EventMessage&)> GetEventCallBack();
		virtual void Init();
		virtual void RunMain();
		virtual void PushLayer(graphics::Layer* layer);
		virtual ~UserApplication();
		//TODO: Remove layer function
	protected:
		// List of layers that the UserApplication holds
		std::vector<graphics::Layer*> layers;
	};
}