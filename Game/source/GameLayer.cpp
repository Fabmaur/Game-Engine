
#include "GameLayer.h"
#include "events/Events.h"
#include "events/InputPoller.h"

void GameLayer::onEvent(EventMessage & event)
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

void GameLayer::Init()
{
	shader = new graphics::Shader("resources/Batch.shader");
	renderer = new graphics::BatchRenderer2D(*shader, 2);
	texture = new graphics::Texture("resources/container.jpg");
	shader->Bind();
	renderable = new graphics::BatchSprite(maths::vec3f(0.1f, 0.2f, 0.0f), maths::vec2f(0.3f, 0.3f), texture);
}

void GameLayer::RunMain()
{
	shader->Bind();
	renderer->Push(renderable);
	renderer->RenderAndPop();
	if (Input::IsKeyPressed(KEY_A))
		HP_SUCCESS("Ayy lmao");
	
}

GameLayer::~GameLayer()
{
	delete renderer;
	delete renderable;
	delete shader;
	delete texture;
}