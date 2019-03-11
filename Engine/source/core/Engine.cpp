#include "pch.h"
#include "Engine.h"

namespace core
{
	Engine::Engine(const char* title, const int width, const int height)
		:window(graphics::Window(title, width, height))
	{
		app = CreateApp();
		HP_STATUS("Initializing Engine");
		window.SetColour(0.4f, 0.2f, 0.6f, 1.0f);
	}

	void Engine::Start()
	{
		window.SetEventCallBack(app->GetEventCallBack());
		app->Init();
	
		while (!window.IsWindowClosed())
		{
			app->RunMain();
			window.Update();
		}
	}

	void Engine::Stop()
	{
		window.Terminate();
	}
}