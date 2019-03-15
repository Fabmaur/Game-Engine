#include "Demo1.h"
#include "graphics/shapes/Cube.h"
#include "graphics/gl_types/Buffers.h"
#include "events/Events.h"
#include "graphics/renderer/Texture.h"

#include <iostream>
#include <iterator>


#include <vector>



void Demo1::onEvent(EventMessage & event)
{
}

void Demo1::Init()
{
	using namespace graphics;

	SetActive(true);

	shader = Shader("resources/Shape.shader");
	tex = new Texture("resources/LogoRealFinal.jpg");
	//proj = maths::Ortho(0.0f, 1920.0f, 0.0f, 1080.0f);

	proj = maths::Perspective(90.0f, ((float)1920 / (float)1080), 0.1f, 100.0f) * maths::TranslateMat(0.0f, -3.0f, -10.0f);
	

	shader.Bind();


	tex->Bind();
	shader.SetUniformMat4f("mvp", proj);
	//shader.SetUniform3v("colour", { 1.0f, 0.1f, 0.2f });
	cube = graphics::Mesh("resources/dragon.obj");
	//cube = graphics::Mesh(cube::vertices, cube::indices);
}

void Demo1::RunMain()
{
	tex->Bind();
	proj.RotateY(0.001f);
	shader.SetUniformMat4f("mvp", proj);
	cube.Draw(shader);
}

Demo1::~Demo1()
{
}