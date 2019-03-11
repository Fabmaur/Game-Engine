#include "Demo1.h"
#include "events/Events.h"
#include "events/InputPoller.h"
#include "graphics/renderer/Mesh.h"
#include <vector>



void Demo1::onEvent(EventMessage & event)
{
	event.ifIs<WindowResize>([](WindowResize& resizeEvent)
	{
		GAME_STATUS(resizeEvent.GetWidth());
		GAME_STATUS(resizeEvent.GetHeight());
	});

	event.ifIs<MousePressed>([](MousePressed& pressedEvent)
	{
		if (pressedEvent.GetButton() == MOUSE_BUTTON_1)
			GAME_STATUS("BAM");
	});
	event.ifIs<MouseReleased>([](MouseReleased& releasedEvent)
	{
		if (releasedEvent.GetButton() == MOUSE_BUTTON_1)
			GAME_STATUS("AHHH");
	});
}

void Demo1::Init()
{
	using namespace graphics;
	shader = new Shader("resources/Shape.shader");
	proj = maths::Perspective(90.0f, 1920.0f / 1080.0f, 0.3f, 100.0f);
#if 0
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	shader = new Shader("resources/Batch.shader");
	mvp = maths::Ortho(0.0f, 1980.0f, 0.0f, 1080.0f);
	//shader->Bind();
	//shader->SetUniformMat4f("mvp", mvp);
	//shader->Unbind();
	renderer = new BatchRenderer2D(shader, 2);
	text = graphics::Text("resources/font.ttf", "FPS:" + std::to_string(timer.getFPS()));
	
	//renderable[0] = new BatchSprite({200.0f, 100.0f, 0.0f }, { 50.0f, 50.0f }, "resources/container.jpg");
	//renderable[0] = new BatchSprite({ 0.5f, 0.8f, -0.9f }, { 0.2f, 0.3f }, "resources/LogoRealFinal.jpg");

#endif
#if 1

#endif


}

void Demo1::RunMain()
{
	std::vector<float> vertices =
	{
	-0.5f, -0.5f, -0.5f, 
	 0.5f, -0.5f, -0.5f, 
	 0.5f,  0.5f, -0.5f, 
	 0.5f,  0.5f, -0.5f, 
	-0.5f,  0.5f, -0.5f, 
	-0.5f, -0.5f, -0.5f, 
						
	-0.5f, -0.5f,  0.5f, 
	 0.5f, -0.5f,  0.5f, 
	 0.5f,  0.5f,  0.5f, 
	 0.5f,  0.5f,  0.5f, 
	-0.5f,  0.5f,  0.5f, 
	-0.5f, -0.5f,  0.5f, 
						
	-0.5f,  0.5f,  0.5f, 
	-0.5f,  0.5f, -0.5f, 
	-0.5f, -0.5f, -0.5f, 
	-0.5f, -0.5f, -0.5f, 
	-0.5f, -0.5f,  0.5f, 
	-0.5f,  0.5f,  0.5f, 
						
	 0.5f,  0.5f,  0.5f, 
	 0.5f,  0.5f, -0.5f, 
	 0.5f, -0.5f, -0.5f, 
	 0.5f, -0.5f, -0.5f, 
	 0.5f, -0.5f,  0.5f, 
	 0.5f,  0.5f,  0.5f, 
						
	-0.5f, -0.5f, -0.5f, 
	 0.5f, -0.5f, -0.5f, 
	 0.5f, -0.5f,  0.5f, 
	 0.5f, -0.5f,  0.5f, 
	-0.5f, -0.5f,  0.5f, 
	-0.5f, -0.5f, -0.5f, 
						
	-0.5f,  0.5f, -0.5f, 
	 0.5f,  0.5f, -0.5f, 
	 0.5f,  0.5f,  0.5f, 
	 0.5f,  0.5f,  0.5f, 
	-0.5f,  0.5f,  0.5f, 
	-0.5f,  0.5f, -0.5f
	};

	std::vector<unsigned int> indices = 
	{
		0,  1,  2,  0,  2,  3,   //front
		4,  5,  6,  4,  6,  7,   //right
		8,  9,  10, 8,  10, 11,  //back
		12, 13, 14, 12, 14, 15,  //left
		16, 17, 18, 16, 18, 19,  //upper
		20, 21, 22, 20, 22, 23   //bottom
	};

	
	maths::mat4f objectMVP = maths::TranslateMat(0.0f, 0.0f, 6.0f) * proj;

	graphics::Mesh object(vertices, indices);
	object.Draw(*shader, objectMVP, {1.0f, 0.5f, 0.5f});



#if 0
	//renderer->Push(renderable[0]);
	//renderer->RenderAndPop();
	text.Push("FPS:"+ std::to_string(timer.getFPS()));
	renderer->RenderText(text, { 0.0f, 0.0f }, { 0.4f, 0.7f, 0.9f, 1.0f });
#endif 
	
}

Demo1::~Demo1()
{
	delete renderer;
	delete[] renderable;
	delete shader;
	delete texture;
}