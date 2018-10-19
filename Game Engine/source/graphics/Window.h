#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include "maths/Vector.h"

namespace graphics {
	class Window
	{
	public:
		Window();
		Window(const char* title, int width, int height);
		void Terminate();
		void CreateWindow(const char* title, int width, int height);
		void Resize() const;
		void SetColour(const float r, const float g, const float b, const float a) const;
		void SetColour(const maths::vec4<float> colour) const;
		void Clear() const;
		bool IsWindowClosed() const;
		inline int GetWidth() const { return width; };
		inline int GetHeight() const { return height; };
	private:
		GLFWwindow* window;
		int width, height;
		const char* title;
	};
}