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
	window.SetColour(0.4f, 0.2f, 0.6f, 1.0f);
}

void Engine::Start()
{
	Shader shader("resources/Shape.shader");

	//Texture tex("resources/container.jpg");
	//
	//Sprite square = Sprite(shader, tex, maths::vec3f{ 0.5f, 0.5f,0.0f }, maths::vec2f{ 0.1f, 0.1f });
	//Sprite square2 = Sprite(shader, tex, maths::vec3f{ 0.2f, 0.3f,0.0f }, maths::vec2f{ 0.1f, 0.6f });
	//SpriteRenderer renderer;
	BatchRenderer2D renderer(1);
	
	shader.Bind();
	Rect rect(maths::vec3f(0.0f, 0.0f, 0.0f), maths::vec2f(0.3f, 0.3f), maths::vec4f(0.3f, 0.5f, 0.2f, 1.0f));

	while (!window.IsWindowClosed())
	{
		renderer.Push(&rect);
		//renderer.Push(&square);
		//renderer.Push(&square2);
		renderer.RenderAndPop();

		window.Update();
    }
}

void core::Engine::Stop()
{
	window.Terminate();
}
