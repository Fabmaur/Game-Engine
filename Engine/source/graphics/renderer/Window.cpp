#include <pch.h>
#include "graphics/renderer/Window.h"
#include "events/Events.h"

namespace graphics
{
	int Window::height;
	int Window::width;

	Window::Window()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		#endif
	}

	Window::Window(const char * titleIn, int widthIn, int heightIn)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		#endif
		CreateWin(titleIn, widthIn, heightIn);

	}

	void graphics::Window::Terminate()
	{
		window = nullptr;
		glfwTerminate();
	}

	void Window::CreateWin(const char* titleIn, int widthIn, int heightIn)
	{
		title = titleIn;
		width = widthIn;
		height = heightIn;
		window = glfwCreateWindow(widthIn, heightIn, titleIn, NULL, NULL);
		if (!window)
		{
			std::cout << "GLFW window failed to be created!" << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(window);

		glfwSetWindowUserPointer(window, this);

		GLenum err = glewInit();
		glfwInit();
		glEnable(GL_DEPTH_TEST);

		if (GLEW_OK != err)
		{
			/* Problem: glewInit failed, something is seriously wrong. */
			fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		}
		fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

		// Sets glfw call back functions

		glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int widthIn, int heightIn)
		{
			Window* mw = static_cast<Window*>(glfwGetWindowUserPointer(window));
			glViewport(0, 0, widthIn, heightIn);
			mw->height = heightIn;
			mw->width = widthIn;
			WindowResize windowResizeEvent(widthIn, heightIn);
			mw->eventCallBack(windowResizeEvent);
		});

		
		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* mw = static_cast<Window*>(glfwGetWindowUserPointer(window));
			switch (action)
			{
			case(GLFW_PRESS):
			{
				KeyPressed keyPressedEvent(key, scancode, mods);
				mw->eventCallBack(keyPressedEvent);
				break;
			}
			case(GLFW_RELEASE):
			{
				KeyReleased keyReleasedEvent(key, scancode, mods);
				mw->eventCallBack(keyReleasedEvent);
				break;
			}
			}
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos)
		{
			Window* mw = static_cast<Window*>(glfwGetWindowUserPointer(window));
			MouseMoved mouseMovedEvent((float)xpos, (float)ypos);
			mw->eventCallBack(mouseMovedEvent);
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
		{
			Window* mw = static_cast<Window*>(glfwGetWindowUserPointer(window));
			
			switch(action)
			{
			case(GLFW_PRESS):
			{
				MousePressed MousePressedEvent(button, mods);
				mw->eventCallBack(MousePressedEvent);
				break;
			}
			case(GLFW_RELEASE):
			{
				MouseReleased MouseReleasedEvent(button, mods);
				mw->eventCallBack(MouseReleasedEvent);
				break;
			}
			}	
		});
	}

	bool Window::IsWindowClosed() const
	{
		return glfwWindowShouldClose(window);
	}

	void Window::SetColour(const float r, const float g, const float b, const float a) const
	{
		glClearColor(r, g, b, a);
	}

	void Window::SetColour(const maths::vec4<float> colour) const
	{
		glClearColor(colour.x, colour.y, colour.z, colour.w);
	}

	void Window::Update() const
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

}