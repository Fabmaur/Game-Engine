#pragma once
#include "EventMessage.h"
#include "maths/Vector.h"

class MouseMoved : public EventMessage
{
	MouseMoved()
		:x(x), y(y) {}
	inline float GetX() const { return x; }
	inline float GetY() const { return y; }
	inline maths::vec2f GetPos() const { return { x, y }; }
	static inline Type GetType() { return Type::MouseMoved; }

private:
	float x, y;
};

class MouseClick : public EventMessage
{
public:
	MouseClick(const int button)
		:button(button)
	{}
	inline int GetButton() const { return button; }
	static inline Type GetType() { return Type::MouseBtnPressed; }
private:
	const int button;
};

class MouseRelease : public EventMessage
{
public:
	MouseRelease(const int button)
		:button(button)
	{}
	inline int GetButton() const { return button; }
	static inline Type GetType() { return Type::MouseBtnReleased; }

private:
	int button;
};