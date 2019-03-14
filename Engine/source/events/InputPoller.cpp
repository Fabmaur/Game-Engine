#include "pch.h"
#include "InputPoller.h"
#include "graphics/renderer/Window.h"


bool Input::IsKeyPressed(int keycode)
{
	HP_ASSERT(graphics::Window::GetGLFWWinPointer() != nullptr, "Window must be initialized!")
	return glfwGetKey(graphics::Window::GetGLFWWinPointer(), keycode) == GLFW_PRESS;
}

bool Input::IsButtonPressed(int button)
{
	HP_ASSERT(graphics::Window::GetGLFWWinPointer() != nullptr, "Window must be initialized!")
	return glfwGetMouseButton(graphics::Window::GetGLFWWinPointer(), button) == GLFW_PRESS;
}

maths::vec2f Input::GetPos()
{
	HP_ASSERT(graphics::Window::GetGLFWWinPointer() != nullptr, "Window must be initialized!")
	double xpos, ypos;
	glfwGetCursorPos(graphics::Window::GetGLFWWinPointer(), &xpos, &ypos);
	return { (float)xpos, (float)ypos };
}

float Input::GetX()
{
	HP_ASSERT(graphics::Window::GetGLFWWinPointer() != nullptr, "Window must be initialized!")
	double xpos, ypos;
	glfwGetCursorPos(graphics::Window::GetGLFWWinPointer(), &xpos, &ypos);
	return (float)xpos;
}

float Input::GetY()
{
	HP_ASSERT(graphics::Window::GetGLFWWinPointer() != nullptr, "Window must be initialized!")
	double xpos, ypos;
	glfwGetCursorPos(graphics::Window::GetGLFWWinPointer(), &xpos, &ypos);
	return (float)ypos;
}

maths::vec2f Input::GetWindowSize()
{
	HP_ASSERT(graphics::Window::GetGLFWWinPointer() != nullptr, "Window must be initialized!")
	int width, height;
	glfwGetWindowSize(graphics::Window::GetGLFWWinPointer(), &width, &height);
	return { width, height };
}

float Input::GetWidth()
{
	HP_ASSERT(graphics::Window::GetGLFWWinPointer() != nullptr, "Window must be initialized!")
	int width, height;
	glfwGetWindowSize(graphics::Window::GetGLFWWinPointer(), &width, &height);
	return width;
}

float Input::GetHeight()
{
	HP_ASSERT(graphics::Window::GetGLFWWinPointer() != nullptr, "Window must be initialized!")
	int width, height;
	glfwGetWindowSize(graphics::Window::GetGLFWWinPointer(), &width, &height);
	return height;
}
