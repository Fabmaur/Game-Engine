#pragma once
#include <GLFW/glfw3.h>
#include "maths/Vector.h"
#include "events/EventMessage.h"


namespace graphics 
{
	/*Window class creates a window using glfw. Also collects events from mouse
	and keyboard.*/
	class Window
	{
	public:
		Window();
		Window(const char* title, int width, int height);
		void Terminate();
		void CreateWin(const char* title, int width, int height);
		void SetColour(const float r, const float g, const float b, const float a) const;
		void SetColour(const maths::vec4<float> colour) const;
		void SetEventCallBack(const std::function<void(EventMessage&)>& eventCall) 
		{ 
			eventCallBack = eventCall;
		}
		void Update() const;
		bool IsWindowClosed() const;
		static inline GLFWwindow* GetGLFWWinPointer() { return window; };
		
	private:
		static GLFWwindow* window;
		static int width, height;
		const char* title;
		std::function<void(EventMessage&)> eventCallBack;

	};
}