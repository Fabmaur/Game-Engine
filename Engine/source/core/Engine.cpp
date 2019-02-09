#include "pch.h"
#include "Engine.h"
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

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
		app->Init();
		window.SetEventCallBack(app->GetEventCallBack());
			
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