#include "Demo3.h"
#include "graphics/renderer/Sprite.h"

void Demo3::onEvent(EventMessage & event)
{
}

void Demo3::Init()
{
	using namespace graphics;
	// Loading resoureces
	shader = Shader("resources/Batch.shader");
	renderer = new BatchRenderer2D(shader, 1000);
	// Creating projection matrix
	proj = maths::Ortho(0.0f, 1980.0f, 0.0f, 1080.0f);
	shader.Bind();
	shader.SetUniformMat4f("mvp", proj);
	// Creating batch sprite
	sprite = new BatchSprite({ 200.0f, 200.0f, 0.0f }, { 200.0f, 200.0f }, "resources/obsidian.png");

}

void Demo3::RunMain()
{
	shader.Bind();
	shader.SetUniformMat4f("mvp", proj);
	// Pushing sprite to renderer and drawing it
	renderer->Push(sprite);
	renderer->RenderAndPop();
}

Demo3::~Demo3()
{
	delete tex;
	delete sprite;
	delete renderer;
}
