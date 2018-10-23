#include "Window.h"

using namespace graphics;

int Window::height;
int Window::width;
bool Window::keys[];
bool Window::buttons[];
double Window::mouseX;
double Window::mouseY;

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
	glfwSetWindowUserPointer(window, this);
	std::cout << window << std::endl;

	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int widthIn, int heightIn)
	{
		Window* mw = static_cast<Window*>(glfwGetWindowUserPointer(window));
		glViewport(0, 0, widthIn, heightIn);
		mw->height = heightIn;
		mw->width = widthIn;
		std::cout << mw << std::endl;

	});

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* mw = static_cast<Window*>(glfwGetWindowUserPointer(window));
		mw->keys[key] = action != GLFW_RELEASE;
	});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos)
	{
		Window* mw = static_cast<Window*>(glfwGetWindowUserPointer(window));
		mw->mouseX = xpos;
		mw->mouseY = ypos;

	});

	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
	{
		Window* mw = static_cast<Window*>(glfwGetWindowUserPointer(window));
		mw->buttons[button] = action != GLFW_RELEASE;
	});

	for (int i = 0; i < MAX_KEYS; i++)
		keys[i] = 0;
	for (int i = 0; i < MAX_BUTTONS; i++)
		keys[i] = 0;

	
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

void Window::Clear() const
{
	glfwSwapBuffers(window);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::isKeyPressed(const unsigned int keycode) const
{
	return keys[keycode];
}