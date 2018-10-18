#include "Window.h"

using namespace graphics;


Window::Window()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif
}

graphics::Window::Window(const char * titleIn, int widthIn, int heightIn)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif
	CreateWindow(titleIn, widthIn, heightIn);

}

Window::~Window()
{
	window = nullptr;
	glfwTerminate();
}

void Window::CreateWindow(const char* titleIn, int widthIn, int heightIn)
{
	title = titleIn;
	width = widthIn;
	height = heightIn;
	window = glfwCreateWindow(widthIn, heightIn, titleIn, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "GLFW window failed to be created!" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	
}



void Window::Resize(int width, int height) const
{
	glfwSetFramebufferSizeCallback(window, [](){});

}


