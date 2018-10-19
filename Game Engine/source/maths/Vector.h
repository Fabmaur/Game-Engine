#pragma once

#include <cmath>
namespace maths {
	template <typename T>
	struct vec2
	{
		//Variables
		T x, y;
		//Methods
		vec2() = default;
		vec2(T x, T y)
			:x(x),
			y(y)
		{};
		inline T operator +(const Vec2<T>& rhs) const
		{
			return Vec2(x + rhs.x, y + rhs.y);
		};
		inline T operator -(const Vec2<T>& rhs) const
		{
			return Vec2(x - rhs.x, y - rhs.y);
		};
		inline T operator *(const Vec2<T>& rhs) const

		{
			return Vec2(x * rhs.x, y * rhs.y);
		};
		inline T operator *(const T& rhs) const
		{
			return Vec2(x*rhs, y*rhs);
		}
		inline float operator /(const Vec2<T>& rhs) const
		{
			return Vec2(x / rhs.x, y / rhs.y);
		};
		inline float operator /(const T& rhs) const
		{
			return Vec2(x / rhs, y / rhs);
		};
		inline operator +=(const Vec2<T>& rhs)
		{
			*this = *this + rhs;
		};
		inline operator -=(const Vec2<T>& rhs)
		{
			*this = *this - rhs;
		};
		inline operator *=(const Vec2<T>& rhs)
		{
			*this = *this * rhs;
		};
		inline operator /=(const Vec2<T>& rhs)
		{
			*this = *this / rhs;
		};
		inline T lenSqr() const
		{
			x * x + y * y;
		}
		inline float len()
		{
			return sqrt((float)lenSqr());
		};
		inline T normalize(const Vec2<T>& rhs)
		{
			const T l = len();
			return l != (T)0 ? *this * (1 / l) : (T)0;
		};
		inline T dotProduct(const Vec2<T>& rhs) const
		{
			return x*rhs.x + y*rhs.y;
		};
	};

	template <typename T>

	struct vec3
	{
		//Variables
		T x, y, z;
		//Methods
		vec3 = default;
		Vec2(T x, T y, T z)
			:x(x),
			y(y),
			z(z)
		{};
		inline T operator +(const Vec2<T>& rhs) const
		{
			return Vec2(x + rhs.x, y + rhs.y, z + rhs.z);
		};
		inline T operator -(const Vec2<T>& rhs) const
		{
			return Vec2(x - rhs.x, y - rhs.y, z - rhs.z);
		};
		inline T operator *(const Vec2<T>& rhs) const

		{
			return Vec2(x * rhs.x, y * rhs.y, z * rhs.z);
		};
		inline T operator *(const T& rhs) const
		{
			return Vec2(x*rhs, y*rhs, z*rhs);
		}
		inline float operator /(const Vec2<T>& rhs) const
		{
			return Vec2(x / rhs.x, y / rhs.y, z / rhs.z);
		};
		inline float operator /(const T& rhs) const
		{
			return Vec2(x / rhs, y / rhs, z / rhs);
		};
		inline operator +=(const Vec2<T>& rhs)
		{
			*this = *this + rhs;
		};
		inline operator -=(const Vec2<T>& rhs)
		{
			*this = *this - rhs;
		};
		inline operator *=(const Vec2<T>& rhs)
		{
			*this = *this * rhs;
		};
		inline operator /=(const Vec2<T>& rhs)
		{
			*this = *this / rhs;
		};
		inline T lenSqr() const
		{
			x * x + y * y + z * z;
		}
		inline float len()
		{
			return sqrt((float)lenSqr());
		};
		inline T normalize(const Vec2<T>& rhs)
		{
			const T l = len();
			return l != (T)0 ? *this * ((T)1 / l) : (T)0;
		};
		inline T dotProduct(const Vec2<T>& rhs) const
		{
			return x*rhs.x + y*rhs.y + z*rhs.z;
		};
	};


	template <typename T>

	struct vec4
	{
		//Variables
		T x, y, z, w;
		//Methods
		vec4 = default;
		Vec4(T x, T y, T z)
			:x(x),
			y(y),
			z(z)
		{};
		inline T operator +(const Vec2<T>& rhs) const
		{
			return Vec2(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		};
		inline T operator -(const Vec2<T>& rhs) const
		{
			return Vec2(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
		};
		inline T operator *(const Vec2<T>& rhs) const

		{
			return Vec2(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
		};
		inline T operator *(const T& rhs) const
		{
			return Vec2(x*rhs, y*rhs, z*rhs, w*rhs.w);
		}
		inline float operator /(const T& rhs) const
		{
			return Vec2(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		};
		inline float operator /(const T& rhs) const
		{
			return Vec2(x / rhs, y / rhs, z / rhs, w / rhs);
		};
		inline operator +=(const Vec2<T>& rhs)
		{
			*this = *this + rhs;
		};
		inline operator -=(const Vec2<T>& rhs)
		{
			*this = *this - rhs;
		};
		inline operator *=(const Vec2<T>& rhs)
		{
			*this = *this * rhs;
		};
		inline operator /=(const Vec2<T>& rhs)
		{
			*this = *this / rhs;
		};
		inline float lenSqr() const
		{
			x*x + y * y + z * z + w * w;
		}
		inline float len()
		{
			return sqrt((float)lenSqr());
		};
		inline T normalize(const Vec2<T>& rhs)
		{
			const T l = len();
			return l != (T)0 ? *this * ((T)1 / l) : (T)0;
		};
		inline T dotProduct(const Vec2<T>& rhs) const
		{
			return x*rhs.x + y*rhs.y + z*rhs.z + w*rhs.w;
		};
	};
}