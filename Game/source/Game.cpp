#include "Game.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Renderable2D.h"
#include "graphics/renderer/BatchRenderer2D.h"

void Game::EventCallBack(EventMessage& event)
{
	event.ifIs<WindowResize>([](WindowResize& resizeEvent)
	{
		GAME_STATUS(resizeEvent.GetWidth());
		GAME_STATUS(resizeEvent.GetHeight());
	});
	event.ifIs<MouseMoved>([](MouseMoved& movedEvent) 
	{
		GAME_STATUS("X:", movedEvent.GetX());
		GAME_STATUS("Y:", movedEvent.GetY());
	});
	event.ifIs<MousePressed>([](MousePressed& pressedEvent) 
	{
		if (pressedEvent.GetButton() == MOUSE_BUTTON_1)
			GAME_STATUS("BAM");
	});
	event.ifIs<MouseReleased>([](MouseReleased& releasedEvent)
	{
		if (releasedEvent.GetButton() == MOUSE_BUTTON_1)
			GAME_STATUS("AHHH");
	});
}

void Game::Init()
{	
	shader = new graphics::Shader("resources/Shape.shader");
	renderer =  new graphics::BatchRenderer2D(1000);
	shader->Bind();
	renderable = new graphics::Rect(maths::vec3f(0.0f, 0.0f, 0.0f), maths::vec2f(0.3f, 0.3f), maths::vec4f(0.3f, 0.5f, 0.2f, 1.0f));
}

void Game::RunMain()
{
	renderer->Push(renderable);
	renderer->RenderAndPop();
}

Game::~Game()
{
	delete renderer;
	delete renderable;
	delete shader;
}
