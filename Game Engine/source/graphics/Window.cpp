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
	CreateWindow(titleIn, widthIn, heightIn);

}

void graphics::Window::Terminate()
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
	if (!window)
	{
		std::cout << "GLFW window failed to be created!" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	
}

bool Window::IsWindowClosed() const
{
	return glfwWindowShouldClose(window);
}



void Window::Resize() const
{
	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); });
}

void Window::SetColour(const float r, const float g, const float b, const float a) const
{
	glClearColor(r, g, b, a);
}

void graphics::Window::SetColour(const maths::vec4<float> colour) const
{
	glClearColor(colour.x, colour.y, colour.z, colour.w);
}

void Window::Clear() const
{
	glfwSwapBuffers(window);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
}


