#include "Engine.h"
using namespace core;


Engine::Engine(const int width, const int height)
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
	while(!window.IsWindowClosed())
	{
		std::cout << window.IsButtonClicked(GLFW_MOUSE_BUTTON_1) << std::endl;
		window.Clear();
	}
}

void core::Engine::Stop()
{
	window.Terminate();
}
