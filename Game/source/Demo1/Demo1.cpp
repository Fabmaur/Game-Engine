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

	proj = maths::Perspective(120.0f, (1920.0f / 1080.0f), 0.2f, 100.0f) * maths::TranslateMat(0.0f, 0.0f, -1.0f);
	maths::vec4f vertex = maths::times(proj, { 0.5, 0.5f, 0.5f, 1.0f });
	vertex = vertex / vertex.w;
	HP_STATUS("X:", vertex.x);
	HP_STATUS("Y:", vertex.y);
	HP_STATUS("Z:", vertex.z);
	HP_STATUS("W:", vertex.w);


	shader.Bind();
	shader.SetUniformMat4f("mvp", proj);
	shader.SetUniform3v("colour", {0.5f, 0.5f, 1.0f});
	cube = graphics::Mesh(cube::vertices, cube::indices);
}

void Demo1::RunMain()
{
	cube.Draw(shader);
}

Demo1::~Demo1()
{
}