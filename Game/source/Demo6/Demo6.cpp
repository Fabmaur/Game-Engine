#include "Demo6.h"
#include "events/Events.h"
#include "graphics/shapes/Cube.h"

void Demo6::onEvent(EventMessage & event)
{
}

void Demo6::Init()
{
	using namespace graphics;
	// Loading resources
	shader = Shader("resources/Default.shader");
	tex = new Texture("resources/stone.jpg");
	block = Mesh(cube::vertices, cube::indices);
	// Creating projection matrix
	proj = maths::Perspective(90.0f, ((float)1920 / (float)1080), 0.1f, 100.0f);
	proj.Translate(0.0f, 0.0f, -2.0f);
}

void Demo6::RunMain()
{
	
	shader.Bind();
	shader.SetUniform1i("tex", tex->GetTUID());
	tex->Bind();
	proj.RotateX(0.0002f);
	proj.RotateY(0.0004f);
	
	shader.SetUniformMat4f("mvp", proj);
	block.Draw();
}
Demo6::~Demo6()
{
	delete tex;
}