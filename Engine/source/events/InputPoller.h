#pragma once
#include "maths/Vector.h"

class Input
{
	/* Asks GLFW for information about input devices or the window. */
public:
	static bool IsKeyPressed(int keycode);
	static bool IsButtonPressed(int button);
	static maths::vec2f GetPos();
	static float GetX();
	static float GetY();
	static maths::vec2f GetWindowSize();
	static float GetWidth();
	static float GetHeight();
};

