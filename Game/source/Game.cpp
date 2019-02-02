#include "Game.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Renderable2D.h"
#include "graphics/renderer/BatchRenderer2D.h"

void Game::Init()
{
	
	shader = new graphics::Shader("resources/Shape.shader");
	renderer =  new graphics::BatchRenderer2D(1);
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
