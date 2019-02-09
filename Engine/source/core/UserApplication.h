#pragma once
#include "events/EventMessage.h"

namespace core
{
	class UserApplication
	{
	public:
		virtual void EventCallBack(EventMessage& event) = 0;
		std::function<void(EventMessage&)> GetEventCallBack() 
		{
			return std::bind(&UserApplication::EventCallBack, this, std::placeholders::_1);
		};
		virtual void Init() = 0;
		virtual void RunMain() = 0;
		virtual ~UserApplication(){}
	};
}