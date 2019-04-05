#include "Demo5.h"
#include "graphics/renderer/Sprite.h"
#include "graphics/renderer/BatchRenderer2D.h"
#include "graphics/renderer/SpriteRenderer.h"


void Demo5::onEvent(EventMessage & event)
{
}

void Demo5::Init()
{
	using namespace graphics;
	// Enabling transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// Setting font and text
	text = Text("resources/font.TTF", "hello world");
	renderer = new SpriteRenderer();

}

void Demo5::RunMain()
{
	// Rendering text
	renderer->RenderText(text, { 200.0f, 200.0f }, {1.0f, 0.0f, 0.0f, 1.0f});
	renderer->RenderText(text, { 400.0f, 400.0f }, { 1.0f, 0.0f, 0.0f, 1.0f });
	renderer->RenderText(text, { 600.0f, 600.0f }, { 1.0f, 0.0f, 0.0f, 1.0f });
	renderer->RenderText(text, { 800.0f, 800.0f }, { 1.0f, 0.0f, 0.0f, 1.0f });

}

Demo5::~Demo5()
{
	delete renderer;
}
