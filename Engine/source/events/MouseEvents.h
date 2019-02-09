#pragma once
#include "EventMessage.h"
#include "maths/Vector.h"

class MouseMoved : public EventMessage
{
public:
	MouseMoved() = default;
	MouseMoved(float x, float y)
		:x(x), y(y) 
	{
		type = Type::MouseMoved;
	}
	inline double GetX() const { return x; }
	inline double GetY() const { return y; }
	inline maths::vec2<double> GetPos() const { return { x, y }; }
	static inline Type GetType() { return Type::MouseMoved; }

private:
	float x, y;
};

class MousePressed : public EventMessage
{
public:
	MousePressed() = default;
	MousePressed(int button, int mods)
		:button(button),
		mods(mods)
	{
		type = Type::MouseBtnPressed;
	}
	inline int GetButton() const { return button; }
	static inline Type GetType() { return Type::MouseBtnPressed; }
private:
	int button;
	int mods;
};

class MouseReleased : public EventMessage
{
public:
	MouseReleased() = default;
	MouseReleased(const int button, int mods)
		:button(button),
		mods(mods)
	{
		type = Type::MouseBtnReleased;
	}
	inline int GetButton() const { return button; }
	static inline Type GetType() { return Type::MouseBtnReleased; }

private:
	int button;
	int mods;
};

#define MOUSE_BUTTON_1   0
#define MOUSE_BUTTON_2   1
#define MOUSE_BUTTON_3   2
#define MOUSE_BUTTON_4   3
#define MOUSE_BUTTON_5   4
#define MOUSE_BUTTON_6   5
#define MOUSE_BUTTON_7   6
#define MOUSE_BUTTON_8   7
#define MOUSE_BUTTON_LAST   MOUSE_BUTTON_8
#define MOUSE_BUTTON_LEFT   MOUSE_BUTTON_1
#define MOUSE_BUTTON_RIGHT   MOUSE_BUTTON_2
#define MOUSE_BUTTON_MIDDLE   MOUSE_BUTTON_3
