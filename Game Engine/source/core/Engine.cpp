#include "Engine.h"
using namespace core;


Engine::Engine(const int width = 800, const int height = 600)
{
	graphics::Window newWindow("Hello World!", width, height);
	window = newWindow;
	window.SetColour(0.2f, 0.4f, 0.3f, 1.0f);
}

Engine::Engine(const char* title, const int width, const int height)
{
	graphics::Window newWindow(title, width, height);
	window = newWindow;
	window.SetColour(0.2f, 0.4f, 0.3f, 1.0f);
}


void Engine::Start()
{
	window.Resize();
	while(!window.IsWindowClosed())
	{
		window.Clear();
	}
}

void core::Engine::Stop()
{
	window.Terminate();
}
