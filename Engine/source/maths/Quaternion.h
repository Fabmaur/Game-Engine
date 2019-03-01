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
		
		inline Quaternion operator+(const Quaternion& rhs)
		{
			return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w };
		}

		inline Quaternion operator-(const Quaternion& rhs) const
		{
			return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w };
		};
		
		inline Quaternion operator*(const Quaternion& rhs)
		{
			float ax = x * rhs.w + w * rhs.x + y * rhs.z - z * rhs.y;
			float ay = y * rhs.w + w * rhs.y + z * rhs.x - x * rhs.z;
			float az = z * rhs.w + w * rhs.z + x * rhs.y - y * rhs.x;
			float aw = w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z;

			return {ax, ay, az, aw};
		}
		
		inline Quaternion operator*(float rhs)
		{
			return { x * rhs, y * rhs, z * rhs, w * rhs };
		}

		inline Quaternion operator*(const vec3f& rhs)
		{
			float aw = -x *rhs.x - y * rhs.y - z * rhs.z;
			float ax = w * rhs.x + y * rhs.z - z * rhs.y;
			float ay = w * rhs.y + z * rhs.x - x * rhs.z;
			float az = w * rhs.z + x * rhs.y - y * rhs.x;

			return { ax, ay, az, aw };
		}

		inline void operator +=(const Quaternion& rhs)
		{
			*this = *this + rhs;
		};

		inline void operator -=(const Quaternion& rhs)
		{
			*this = *this - rhs;
		};

		inline void operator *=(const Quaternion& rhs)
		{
			*this = *this * rhs;
		};


		inline void operator *=(const vec3f& rhs)
		{
		*this = *this * rhs;
		};

		inline void operator *=(float rhs)
		{
			*this = *this * rhs;
		};

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

		inline float length()
		{
			return sqrt(x * x + y * y + z * z + w * w);
		}

	public:
		union
		{
			struct { float x, y, z, w; };
			struct { vec4f quaternion; };
		};
	};
}