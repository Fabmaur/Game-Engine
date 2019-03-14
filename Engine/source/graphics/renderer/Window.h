#pragma once
#include <GLFW/glfw3.h>
#include "maths/Vector.h"
#include "events/EventMessage.h"


namespace graphics 
{
	/* Window class creates and manages a window using glfw. And activates
	an event call back when event occurs. */
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
		// Callable variable which holds the event call back
		std::function<void(EventMessage&)> eventCallBack;

	};
}