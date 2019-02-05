#pragma once
#include "events/EventMessage.h"

namespace core
{
	class UserApplication
	{
	public:
		virtual bool EventCallBack(EventMessage& event) = 0;
		void SetEventCallBack(std::function<bool(EventMessage)> eventmessage) 
		{
			std::bind(&UserApplication::EventCallBack, this, std::placeholders::_1);
		};
		virtual void Init() = 0;
		virtual void RunMain() = 0;
	};
}