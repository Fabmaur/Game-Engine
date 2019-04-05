#include "Demo7.h"
#include "events/Events.h"
#include "graphics/renderer/Sprite.h"
#include "graphics/renderer/BatchRenderer2D.h"
#include "graphics/renderer/SpriteRenderer.h"


void Demo7::onEvent(EventMessage & event)
{
	/* Checking for different events with the ifIs function
	and a lamda function which processes event data.*/
	event.ifIs<WindowResize>([](WindowResize& resizeEvent)
	{
		GAME_STATUS(resizeEvent.GetWidth());
		GAME_STATUS(resizeEvent.GetHeight());
	});

	event.ifIs<MousePressed>([](MousePressed& pressedEvent)
	{
		if (pressedEvent.GetButton() == MOUSE_BUTTON_1)
			GAME_STATUS("Click");
	});
	event.ifIs<MouseReleased>([](MouseReleased& releasedEvent)
	{
		if (releasedEvent.GetButton() == MOUSE_BUTTON_1)
			GAME_STATUS("Release");
	});
	event.ifIs<KeyPressed>([](KeyPressed& keyPressedEvent)
	{
		if (keyPressedEvent.GetKeycode() == KEY_A)
			GAME_STATUS("A");
	});
}

void Demo7::Init()
{
}

void Demo7::RunMain()
{
	// Polling input class about input data
	if (Input::IsKeyPressed(KEY_S))
		GAME_SUCCESS("Success");
	if (Input::IsKeyPressed(KEY_A))
		GAME_STATUS("Status");
	if (Input::IsKeyPressed(KEY_E))
		GAME_ERROR("Error");
	if(Input::IsKeyPressed(KEY_W))
		GAME_WARNING("Warning");
	if (Input::IsKeyPressed(KEY_F))
		GAME_FATAL("Fatal");
}

Demo7::~Demo7()
{
	delete renderer;
}
