#include "Demo4.h"
#include "graphics/renderer/Sprite.h"
#include "graphics/renderer/BatchRenderer2D.h"

void Demo4::onEvent(EventMessage & event)
{
}

void Demo4::Init()
{
	using namespace graphics;
	
	// Loading resources
	shader = Shader("resources/Batch.shader");
	renderer = new BatchRenderer2D(shader, 1000);
	// Creating projection matrix
	proj = maths::Ortho(0.0f, 1980.0f, 0.0f, 1080.0f);
	shader.Bind();
	shader.SetUniformMat4f("mvp", proj);
	// Creating list of sprites
	sprite[0] = new BatchSprite({ 200.0f, 200.0f, 0.0f }, { 200.0f, 200.0f }, "resources/obsidian.png");
	sprite[1] = new BatchSprite({ 400.0f, 200.0f, 0.0f }, { 200.0f, 200.0f }, "resources/stone.jpg");
	sprite[2] = new BatchSprite({ 600.0f, 200.0f, 0.0f }, { 200.0f, 200.0f }, "resources/marble.jpg");
}

void Demo4::RunMain()
{
	shader.Bind();
	shader.SetUniformMat4f("mvp", proj);
	// Pushing sprites to renderer and drawing
	renderer->Push(sprite[0]);
	renderer->Push(sprite[1]);
	renderer->Push(sprite[2]);

	renderer->RenderAndPop();
}

Demo4::~Demo4()
{
	delete tex;
	delete[] sprite;
	delete renderer;
}
