#pragma once

#include <cmath>
#include <iostream>

namespace maths
{
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
		inline vec2<T> operator +(const vec2<T>& rhs) const
		{
			return { x + rhs.x, y + rhs.y };
		};
		inline vec2<T> operator -(const vec2<T>& rhs) const
		{
			return vec2(x - rhs.x, y - rhs.y);
		};
		inline vec2<T> operator *(const vec2<T>& rhs) const
		{
			return { x * rhs.x, y * rhs.y };
		};
		inline vec2<T> operator *(const T& rhs) const
		{
			return {x*rhs, y*rhs};
		}
		inline vec2<T> operator /(const vec2<T>& rhs) const
		{
			return { x / rhs.x, y / rhs.y };
		};
		inline vec2<T> operator /(const T& rhs) const
		{
			return {x / rhs, y / rhs};
		};
		inline void operator +=(const vec2<T>& rhs)
		{
			*this = *this + rhs;
		};
		inline void operator-=(const vec2<T>& rhs)
		{
			*this = *this - rhs;
		};
		inline void operator*=(const vec2<T>& rhs)
		{
			*this = *this * rhs;
		};
		inline void operator/=(const vec2<T>& rhs)
		{
			*this = *this / rhs;
		};
		inline T lenSqr() const
		{
			return x * x + y * y;
		}
		inline float len()
		{
			return sqrt((float)lenSqr());
		};
		inline T normalize(const vec2<T>& rhs)
		{
			const T l = len();
			return l != (T)0 ? *this * (1 / l) : (T)0;
		};
		inline T dotProduct(const vec2<T>& rhs) const
		{
			return x*rhs.x + y*rhs.y;
		};
		inline T operator[](const int index) const
		{
			return (index == 0) ? x : y;
		}

	};

	typedef vec2<int> vec2i;
	typedef vec2<float> vec2f;


	template <typename T>

	struct vec3
	{
		//Variables
		T x, y, z;
		//Methods
		vec3() = default;
		vec3(T x, T y, T z)
			:x(x),
			y(y),
			z(z)
		{};
		inline vec3<T> operator +(const vec3<T>& rhs) const
		{
			return { x + rhs.x, y + rhs.y, z + rhs.z };
		};
		inline vec3<T> operator -(const vec2<T>& rhs) const
		{
			return { x - rhs.x, y - rhs.y, z - rhs.z };
		};
		inline vec3<T> operator *(const vec3<T>& rhs) const

		{
			return { x * rhs.x, y * rhs.y, z * rhs.z };
		};
		inline vec3<T> operator *(const T& rhs) const
		{
			return { x*rhs, y*rhs, z*rhs };
		}
		inline vec3<T> operator /(const vec3<T>& rhs) const
		{
			return { x / rhs.x, y / rhs.y, z / rhs.z };
		};
		inline vec3<T> operator /(const T& rhs) const
		{
			return { x / rhs, y / rhs, z / rhs };
		};
		inline void operator +=(const vec3<T>& rhs)
		{
			*this = *this + rhs;
		};
		inline void operator -=(const vec3<T>& rhs)
		{
			*this = *this - rhs;
		};
		inline void operator *=(const vec3<T>& rhs)
		{
			*this = *this * rhs;
		};
		inline void operator /=(const vec3<T>& rhs)
		{
			*this = *this / rhs;
		};
		inline T lenSqr() const
		{
			return x * x + y * y + z * z;
		}
		inline float len()
		{
			return sqrt((float)lenSqr());
		};
		inline T normalize(const vec3<T>& rhs)
		{
			const T l = len();
			return l != (T)0 ? *this * ((T)1 / l) : (T)0;
		};
		inline T dotProduct(const vec3<T>& rhs) const
		{
			return x*rhs.x + y*rhs.y + z*rhs.z;
		};
	};

	typedef vec3<int> vec3i;
	typedef vec3<float> vec3f;

	template <typename T>

	struct vec4
	{
		//Variables
		T x, y, z, w;
		//Methods
		vec4() = default;
		vec4(T x, T y, T z, T w)
			:x(x),
			y(y),
			z(z),
			w(w)
		{};
		inline vec4<T> operator +(const vec4<T>& rhs) const
		{
			return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w };
		};
		inline vec4<T> operator -(const vec4<T>& rhs) const
		{
			return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w };
		};
		inline T operator *(const vec4<T>& rhs) const
		{
			return { x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w };
		};
		inline T operator *(const T& rhs) const
		{
			return { x*rhs, y*rhs, z*rhs, w*rhs.w };
		}
		inline vec4<T> operator /(const vec4<T>& rhs) const
		{
			return { x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w };
		};
		inline vec4<T> operator /(const T& rhs) const
		{
			return { x / rhs, y / rhs, z / rhs, w / rhs };
		};
		inline void operator +=(const vec4<T>& rhs)
		{
			*this = *this + rhs;
		};
		inline void operator -=(const vec4<T>& rhs)
		{
			*this = *this - rhs;
		};
		inline void operator *=(const vec4<T>& rhs)
		{
			*this = *this * rhs;
		};
		inline void operator /=(const vec4<T>& rhs)
		{
			*this = *this / rhs;
		};
		inline T lenSqr() const
		{
			return x*x + y * y + z * z + w * w;
		}
		inline float len()
		{
			return sqrt((float)lenSqr());
		};
		inline T normalize(const vec4<T>& rhs)
		{
			const T l = len();
			return l != (T)0 ? *this * ((T)1 / l) : (T)0;
		};
		inline T dotProduct(const vec4<T>& rhs) const
		{
			return x*rhs.x + y*rhs.y + z*rhs.z + w*rhs.w;
		};

		inline T operator[](const int index) const
		{
			switch (index)
			{
			case 0: return x;
				break;
			case 1: return y;
				break;
			case 2: return z;
				break;
			case 3: return w;
				break;
			}
		}
	};

	typedef vec4<int> vec4i;
	typedef vec4<float> vec4f;
}