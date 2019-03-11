#pragma once
#include "events/EventMessage.h"
#include "graphics/renderer/Layer.h"

namespace core
{
	class UserApplication
	{
	public:
		virtual void EventCallBack(EventMessage& event)
		{
			for (auto& layer : layers)
			{
				if (layer->IsActive())
					layer->onEvent(event);
			}
		}
		std::function<void(EventMessage&)> GetEventCallBack() 
		{
			return std::bind(&UserApplication::EventCallBack, this, std::placeholders::_1);
		};
		virtual void Init()
		{
			for (auto& layer : layers)
				layer->Init();
		}
		virtual void RunMain()
		{
			for (auto& layer : layers)
				if (layer->IsActive())
					layer->RunMain();
		}
		virtual void PushLayer(graphics::Layer* layer)
		{
			layers.push_back(layer);
		}
		virtual ~UserApplication() 
		{
			for (auto itr = layers.begin(); itr < layers.end(); itr++)
			{
				delete *itr;
				itr = layers.erase(itr);
			}
		};
	protected:
		std::vector<graphics::Layer*> layers;
	};
}