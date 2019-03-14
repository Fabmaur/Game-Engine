#include "pch.h"
#include "UserApplication.h"

namespace core
{
	void UserApplication::EventCallBack(EventMessage & event)
	{
		// Running event code for list of layers
		for (auto& layer : layers)
			if (layer->IsActive())
				layer->onEvent(event);
	}
	std::function<void(EventMessage&)> UserApplication::GetEventCallBack()
	{
		// Binding EventCallBack function into callable object and then returning it
		return std::bind(&UserApplication::EventCallBack, this, std::placeholders::_1);
	}
	void UserApplication::Init()
	{
		// Initializing list of layers
		for (auto& layer : layers)
			layer->Init();
	}

	void UserApplication::RunMain()
	{
		// Running main code for list of layers
		for (auto& layer : layers)
			if (layer->IsActive())
				layer->RunMain();
	}
	void UserApplication::PushLayer(graphics::Layer * layer)
	{
		layers.push_back(layer);
	}
	UserApplication::~UserApplication()
	{
		for (auto itr = layers.begin(); itr < layers.end(); itr++)
		{
			// Going through each layer and freeing the memory
			delete *itr;
			itr = layers.erase(itr);
		}
	}
}