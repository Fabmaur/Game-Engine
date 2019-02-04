#pragma once
#include "EventMessage.h"

class KeyPressed : public EventMessage
{
public:
	KeyPressed(const int key)
		:keycode(key)
	{}
	inline int GetKeycode() const { return keycode; }
	static inline Type GetType() { return Type::KeyPressed; }
private:
	const int keycode;
};

class KeyReleased : public EventMessage
{
public:
	KeyReleased(const int key)
		:keycode(key)
	{}
	inline int GetKeycode() const { return keycode; }
	static inline Type GetType() { return Type::KeyReleased; }
private:
	int keycode;
};