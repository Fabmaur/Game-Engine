#include "pch.h"
#include "UserApplication.h"

namespace core
{
	void UserApplication::EventCallBack(EventMessage & event)
	{
		for (auto& layer : layers)
			if (layer->IsActive())
				layer->onEvent(event);
	}
}