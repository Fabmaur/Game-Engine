#pragma once
#include <GLFW/glfw3.h>

#include <iostream>

namespace graphics {
	class Window
	{
	public:
		Window();
		Window(const char* title, int width, int height);
		~Window();
		void CreateWindow(const char* title, int width, int height);
		
		void Resize(int width, int height) const;
		int GetWidth() const { return width; };
		int GetHeight() const { return height; };
	private:
		GLFWwindow* window;
		int width, height;
		const char* title;
	};
}