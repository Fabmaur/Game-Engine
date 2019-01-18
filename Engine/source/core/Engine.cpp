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

	maths::mat4f model(1.0f);

	Shader shader("source/graphics/renderer/resources/Default.shader");
	shader.Bind();

	Texture tex("source/graphics/renderer/resources/container.jpg");
	tex.Bind();
	shader.SetUniform1f("tex", 0);

	VertexArray VAO;
	VAO.SetInOne(VBO);
	VAO.Bind();




	maths::mat4f view = maths::mat4f::TranslateMat(0.0f, 0.0f, -2.0f);
	while (!window.IsWindowClosed())
	{

		maths::mat4f proj = maths::Perspective(90.0f, (float)window.GetWidth() / (float)window.GetHeight(), 0.3f, 100.0f);
		model.RotateY(0.0001f);
		model.RotateX(0.0001f);
		
		
		
;		// To fix: Applying multiple rotational transformations does not work on a single model
		// To fix: Investigate why values below 0.3f don't work for the near plane of perspective matrix
		
		maths::mat4f mvp =  proj * view * model;

		shader.SetUniformMat4f("mvp", mvp);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		window.Update();
    }
}

void core::Engine::Stop()
{
	window.Terminate();
}
