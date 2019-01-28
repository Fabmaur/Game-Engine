#include "pch.h"
#include "Engine.h"

using namespace core;
using namespace graphics;

Engine::Engine(const int width, const int height)
{
	HP_STATUS("Initializing Engine");
	graphics::Window newWindow("Hello World!", width, height);
	window = newWindow;
	window.SetColour(0.2f, 0.4f, 0.3f, 1.0f);
}

Engine::Engine(const char* title, const int width, const int height)
{
	HP_STATUS("Initializing Engine");
	graphics::Window newWindow(title, width, height);
	window = newWindow;
	window.SetColour(0.2f, 0.4f, 0.3f, 1.0f);
}

void Engine::Start()
{
	Shader shader("resources/Default.shader");
	Texture tex("resources/container.jpg");

	Sprite square(shader, tex, maths::vec3f{ 0.5f, 0.5f,0.0f }, maths::vec2f{ 0.1f, 0.1f });
	SpriteRenderer renderer;


	while (!window.IsWindowClosed())
	{
		renderer.Push(square);
		renderer.Flush();

		window.Update();
    }
}

void core::Engine::Stop()
{
	window.Terminate();
}
