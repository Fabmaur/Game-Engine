#include "Demo2.h"

void Demo2::onEvent(EventMessage & event)
{
}

void Demo2::Init()
{
	using namespace graphics;
	// Loading resources
	tex = new Texture("resources/stone.jpg");
	shader = Shader("resources/Default.shader");
	// Creating projection matrix
	proj = maths::Ortho(0.0f, 1980.0f, 0.0f, 1080.0f);
	shader.Bind();
	shader.SetUniformMat4f("mvp", proj);
	// Creating Single sprite
	sprite = new SingleSprite(shader,*tex, { 200.0f, 200.0f, 0.0f }, { 200.0f, 200.0f});

}

void Demo2::RunMain()
{
	
	shader.Bind();
	tex->Bind();
	shader.SetUniformMat4f("mvp", proj);
	// Pushing and then drawing sprite
	renderer.Push(sprite);
	renderer.RenderAndPop();
}

Demo2::~Demo2()
{
	delete tex;
	delete sprite;
}
