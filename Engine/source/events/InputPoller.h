#pragma once
#include "maths/Vector.h"

class Input
{
public:
	static bool IsKeyPressed(int keycode);
	static bool IsButtonPressed(int button);
	static maths::vec2f GetPos();
	static float GetX();
	static float GetY();
};

