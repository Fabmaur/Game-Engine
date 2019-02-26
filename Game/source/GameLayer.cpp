
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
	using namespace graphics;
	shader = new Shader("resources/Batch.shader");
	renderer = new BatchRenderer2D(shader, 3);
	
	renderable[0] = new BatchSprite({ 0.1f, 0.2f, 0.0f }, { 0.3f, 0.3f }, "resources/container.jpg");
	renderable[1] = new BatchSprite({ 0.5f, 0.8f, 0.0f }, { 0.2f, 0.3f }, "resources/LogoRealFinal.jpg");

}

void GameLayer::RunMain()
{
	renderer->Push(renderable[0]);
	renderer->Push(renderable[1]);
	renderer->RenderAndPop();
}

GameLayer::~GameLayer()
{
	delete renderer;
	delete[] renderable;
	delete shader;
	delete texture;
}