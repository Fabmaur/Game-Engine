#include "pch.h"
#include "Engine.h"

using namespace core;
using namespace graphics;

Engine::Engine(const int width, const int height)
{
	app = CreateApp();
	HP_STATUS("Initializing Engine");
	graphics::Window newWindow("Hello World!", width, height);
	window = newWindow;
	window.SetColour(0.2f, 0.4f, 0.3f, 1.0f);
}

Engine::Engine(const char* title, const int width, const int height)
{
	app = CreateApp();
	HP_STATUS("Initializing Engine");
	graphics::Window newWindow(title, width, height);
	window = newWindow;
	window.SetColour(0.4f, 0.2f, 0.6f, 1.0f);
}

void Engine::Start()
{
	app->Init();

	while (!window.IsWindowClosed())
	{
		app->RunMain();
		window.Update();
    }
}

void core::Engine::Stop()
{
	window.Terminate();
}
