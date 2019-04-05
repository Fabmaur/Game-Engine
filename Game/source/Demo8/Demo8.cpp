#include "Demo8.h"
#include "graphics/gl_types/Buffers.h"
#include "events/Events.h"
#include "graphics/renderer/Texture.h"
#include "graphics/renderer/CameraFPS.h"

void Demo8::onEvent(EventMessage& event)
{
	event.ifIs<MouseMoved>([this](MouseMoved& mouseMovedEvent)
	{
		// Updating camera when mouse moved
		camera.UpdateLook(mouseMovedEvent.GetX(), mouseMovedEvent.GetY());
	});
}

void Demo8::Init()
{
	using namespace graphics;
	// Loading resources
	shader = Shader("resources/Object.shader");
	tex = new Texture("resources/img.jpg");
	dragon = graphics::Mesh("resources/dragon.obj");
	camera = CameraFPS({ 0.0f, 3.0f, 10.0f });
	// Creating perspective projection matrix
	proj = maths::Perspective(90.0f, ((float)1920 / (float)1080), 0.1f, 100.0f);
	proj.Translate(0.0f, -3.0f, -10.0f);
	// Setting object settings
	float shininess = 0.3f;
	float shineDampness = 0.5f;
	// Setting shader uniforms
	shader.Bind();
	shader.SetUniform3v("lightPos", { 0.0f, 0.0f, -3.0f });
	shader.SetUniform3v("lightColour", { 0.6f, 1.0f , 0.7f });
	shader.SetUniform1f("shininess", shininess);
	shader.SetUniform1f("shineDampness", shineDampness);
}

void Demo8::RunMain()
{
	shader.Bind();
	tex->Bind();
	// Checking keyboard for input and responding
	// with momement
	if (Input::IsKeyPressed(KEY_W))
		camera.MoveForward(0.001f);
	if (Input::IsKeyPressed(KEY_S))
		camera.MoveBackward(0.001f);
	if (Input::IsKeyPressed(KEY_A))
		camera.MoveLeft(0.001f);
	if (Input::IsKeyPressed(KEY_D))
		camera.MoveRight(0.001f);

	shader.SetUniformMat4f("mvp", proj * camera.GetViewMat());
	dragon.Draw();
}

Demo8::~Demo8()
{
	delete tex;
}