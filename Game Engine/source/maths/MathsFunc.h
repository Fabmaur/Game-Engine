#pragma once

#define pi 3.14159f

namespace maths {
	inline float GetRadians(const float angle)
	{
		return (angle / 180.0f) * pi;
	}

}