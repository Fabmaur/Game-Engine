#pragma once
#include "events/EventMessage.h"
#include "maths/Matrix4.h"

namespace graphics
{
	class Layer
	{
	public:
		virtual void onEvent(EventMessage& event) = 0;
		virtual void Init() = 0;
		virtual void RunMain() = 0;
		virtual ~Layer() {};
	private:
		maths::mat4f projMat;
	};
}