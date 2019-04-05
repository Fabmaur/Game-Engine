#include "Demo1.h"
#include "graphics/gl_types/Buffers.h"
#include "events/Events.h"
#include "graphics/renderer/Texture.h"
#include "graphics/renderer/CameraFPS.h"

void Demo1::onEvent(EventMessage & event)
{
}

void Demo1::Init()
{
	using namespace graphics;

	// Loading in file data
	shader = Shader("resources/Object.shader");
	tex = new Texture("resources/img.jpg");
	dragon = graphics::Mesh("resources/dragon.obj");

	// Creating perspective matrix and changing view position
	proj = maths::Perspective(90.0f, ((float)1920 / (float)1080), 0.1f, 100.0f);
	proj.Translate(0.0f, -3.0f, -10.0f);
	// Setting shininess of material
	float shininess = 0.3f;
	float shineDampness = 0.5f;
	// Setting uniform settings for shader
	shader.Bind();
	shader.SetUniform3v("lightPos", { 0.0f, 0.0f, -3.0f });
	shader.SetUniform3v("lightColour", { 0.6f, 1.0f , 0.7f });
	shader.SetUniform1f("shininess", shininess);
	shader.SetUniform1f("shineDampness", shineDampness);
}

void Demo1::RunMain()
{
	shader.Bind();
	tex->Bind();
	// Rotating object
	proj.RotateY(0.0003f);
	shader.SetUniformMat4f("mvp", proj);

	dragon.Draw();
}

Demo1::~Demo1()
{
	delete tex;
}