
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


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	shader = new Shader("resources/Batch.shader");
	mvp = maths::Ortho(0.0f, 1980.0f, 0.0f, 1080.0f);
	//shader->Bind();
	//shader->SetUniformMat4f("mvp", mvp);
	//shader->Unbind();
	renderer = new BatchRenderer2D(shader, 2);
	text = graphics::Text("resources/font.ttf", "FPS:" + std::to_string(timer.getFPS()));

	//renderable[0] = new BatchSprite({200.0f, 100.0f, 0.0f }, { 50.0f, 50.0f }, "resources/container.jpg");
	//renderable[0] = new BatchSprite({ 0.5f, 0.8f, -0.9f }, { 0.2f, 0.3f }, "resources/LogoRealFinal.jpg");

}

void GameLayer::RunMain()
{
	//renderer->Push(renderable[0]);
	//renderer->RenderAndPop();
	text.Push("FPS:" + std::to_string(timer.getFPS()));
	renderer->RenderText(text, { 0.0f, 0.0f }, { 0.4f, 0.7f, 0.9f, 1.0f });

}

GameLayer::~GameLayer()
{
	delete renderer;
	delete[] renderable;
	delete shader;
	delete texture;
}