#pragma once

namespace maths 
{
	constexpr float pi = 3.14159f;
	inline float GetRadians(const float angle)
	{
		return (angle / 180.0f) * pi;
	}

}