#pragma once
#include "events/EventMessage.h"
#include "maths/Matrix4.h"

namespace graphics
{
	/* Layer interface which is used to sort the order 
	a game is processed in the engine. */
	class Layer
	{
	public:
		// Function ran when an event takes place on the layer
		virtual void onEvent(EventMessage& event) = 0;
		// Function ran when layer is initialized
		virtual void Init() = 0;
		// Function ran in the main loop
		virtual void RunMain() = 0;
		// Used to activate or deactivate a layer
		void SetActive(bool active_) { active = active_; };
		bool IsActive() const { return active; }
		virtual ~Layer() {}

	private:
		maths::mat4f projMat;
		bool active = true;
	};
}