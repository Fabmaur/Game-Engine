#include "Demo1.h"
#include "graphics/shapes/Cube.h"
#include "graphics/gl_types/Buffers.h"

#include <vector>



void Demo1::onEvent(EventMessage & event)
{
}

void Demo1::Init()
{
	using namespace graphics;

	SetActive(true);

	shader = Shader("resources/Shape.shader");
	//proj = maths::Ortho(0.0f, 1920.0f, 0.0f, 1080.0f);

	proj = maths::Perspective(90.0f, (1920.0f / 1080.0f), 0.0f, 100.0f) * maths::TranslateMat(0.0f, 0.0f, -0.5f);

	maths::vec4f vertex{ 0.5f, 0.5f, 0.0f, 1.0f };
	vertex = maths::times(proj, vertex);
	HP_STATUS("X:",vertex.x);
	HP_STATUS("Y:", vertex.y);
	HP_STATUS("Z:", vertex.z);
	HP_STATUS("W:", vertex.w);
	
	
	shader.Bind();
	shader.SetUniformMat4f("mvp", proj);
	shader.SetUniform3v("colour", {0.8f, 0.5f, 0.5f});
}

void Demo1::RunMain()
{
	proj.RotateY(0.0001f);
	cube.Draw(shader);
}

Demo1::~Demo1()
{
}