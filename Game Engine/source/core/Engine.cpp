#include "Engine.h"

using namespace core;
using namespace graphics;

Engine::Engine(const int width, const int height)
{
	graphics::Window newWindow("Hello World!", width, height);
	window = newWindow;
	window.SetColour(0.2f, 0.4f, 0.3f, 1.0f);
}

Engine::Engine(const char* title, const int width, const int height){
	graphics::Window newWindow(title, width, height);
	window = newWindow;
	window.SetColour(0.2f, 0.4f, 0.3f, 1.0f);
}

void Engine::Start()
{
	VertexBuffer VBO(graphics::CubeTextured::vertices, sizeof(graphics::CubeTextured::vertices));
	VBO.PushLayout(3, GL_FLOAT);
	VBO.PushLayout(2, GL_FLOAT);

	maths::mat4<float> model(1.0f);

	maths::mat4f view;
	maths::mat4f proj;
	
	Shader shader("source/graphics/renderer/resources/Default.shader");
	shader.Bind();

	Texture tex("source/graphics/renderer/resources/LogoRealFinal.jpg");
	tex.Bind();
	shader.SetUniform1f("tex", 0);

	VertexArray VAO;
	VAO.SetInOne(VBO);
	VAO.Bind();

	
	while (!window.IsWindowClosed())
	{
		glDrawArrays(GL_TRIANGLES, 0, 36);
		window.Update();
    }
}

void core::Engine::Stop()
{
	window.Terminate();
}
