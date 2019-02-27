#pragma once

#include "Vector.h"

namespace maths
{
	class Quaternion
	{
	public:
		Quaternion(const vec4f quaternion)
			:quaternion(quaternion)
		{}
		
		Quaternion(float x, float y, float z, float w)
			:quaternion({x, y, z, w})
		{}
		
		inline float length()
		{
			return sqrt(x * x + y * y + z * z + w * w);
		}

		inline Quaternion& normalize()
		{
			float length = this->length();
			x /= length;
			y /= length;
			z /= length;
			w /= length;
			return *this;
		};

		inline Quaternion& conjugate()
		{
			x = -x;
			y = -y;
			z = -z;
			w =  w;
			return *this;

		}

		inline Quaternion operator*(const Quaternion& rhs)
		{
			float aw = w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z;
			float ax = x * rhs.w + w * rhs.x + y * rhs.z - z * rhs.y;
			float ay = y * rhs.w + w * rhs.y + z * rhs.x - x * rhs.z;
			float az = z * rhs.w + w * rhs.z + x * rhs.y - y * rhs.x;

			return {ax, ay, ay, az};
		}


		template <typename T>
		inline Quaternion operator*(const T& rhs)
		{

		}

		inline Quaternion operator+(const Quaternion& rhs)
		{
			return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w };
		}

		inline Quaternion operator-(const Quaternion& rhs) const
		{
			return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w };
		};

		union
		{
			struct { float x, y, z, w; };
			struct { vec4f quaternion; };
		};
	};
}