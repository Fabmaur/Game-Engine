#pragma once
#include "events/EventMessage.h"

namespace core
{
	class UserApplication
	{
	public:
		virtual void EventCallBack(EventMessage& event) = 0;
		virtual void Init() = 0;
		virtual void RunMain() = 0;
		auto GetEventCallBack()
		{
			return std::bind(&UserApplication::EventCallBack, this, std::placeholders::_1);

		}
	};
}