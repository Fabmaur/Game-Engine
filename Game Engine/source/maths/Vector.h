#pragma once
#include <cmath>

template <typename T>
struct Vec2
{
public:
	T x, y;
public:
	vec2 = default;
	Vec2(T x, T y)
		:x(x),
		y(y)
	{};
	inline T operator +(const T& rhs) const 
	{
		return Vec2(x + rhs.x, y + rhs.y);
	};
	inline T operator -(const T& rhs) const
	{
		return Vec2(x - rhs.x, y - rhs.y);
	};
	inline T operator *(const T& rhs) const

	{
		return Vec2(x * rhs.x, y * rhs.y);
	};
	inline T operator *(const int& rhs) const
	{
		return Vec2(x*rhs, y*rhs);
	}
	inline float operator /(const T& rhs) const
	{
		return Vec2(x / rhs.x, y / rhs.y);
	};
	inline float operator /(const int& rhs) const
	{
		return Vec2(x / rhs, y / rhs);
	};
	inline operator +=(const T& rhs)
	{
		*this = *this + rhs;
	};
	inline operator -=(const T& rhs)
	{
		*this = *this - rhs;
	};
	inline operator *=(const T& rhs)
	{
		*this = *this * rhs;
	};
	inline operator /=(const T& rhs)
	{
		*this = *this / rhs;
	};
	inline float lenSqr() const
	{
		x * x + y * y;
	}
	inline float len()
	{
		return sqrt(lenSqr());
	};
	inline normalize(const T& rhs)
	{
		const T l = len();
		return l != (T)0 ? *this * (1/l) : (T)0;
	};
	inline T dotProduct(const T& rhs) const
	{
		return *this.x*rhs.x + *this.y*y;
	};
};

template <typename T>

struct Vec3
{
public:
	T x, y, z;
public:
	vec2 = default;
	Vec2(T x, T y, T z)
		:x(x),
		y(y),
		z(z)
	{};
	inline T operator +(const T& rhs) const
	{
		return Vec2(x + rhs.x, y + rhs.y, z + rhs.z);
	};
	inline T operator -(const T& rhs) const
	{
		return Vec2(x - rhs.x, y - rhs.y, z - rhs.z);
	};
	inline T operator *(const T& rhs) const

	{
		return Vec2(x * rhs.x, y * rhs.y, z * rhs.z);
	};
	inline T operator *(const int& rhs) const
	{
		return Vec2(x*rhs, y*rhs, z*rhs);
	}
	inline float operator /(const T& rhs) const
	{
		return Vec2(x / rhs.x, y / rhs.y, z / rhs.z);
	};
	inline float operator /(const int& rhs) const
	{
		return Vec2(x / rhs, y / rhs, z / rhs);
	};
	inline operator +=(const T& rhs)
	{
		*this = *this + rhs;
	}; 
	inline operator -=(const T& rhs)
	{
		*this = *this - rhs;
	};
	inline operator *=(const T& rhs)
	{
		*this = *this * rhs;
	};
	inline operator /=(const T& rhs)
	{
		*this = *this / rhs;
	};
	inline float lenSqr() const
	{
		x * x + y * y + z*z;
	}
	inline float len()
	{
		return sqrt(lenSqr());
	};
	inline normalize(const T& rhs)
	{
		const T l = len();
		return l != (T)0 ? *this * ((T)1 / l) : (T)0;
	};
	inline T dotProduct(const T& rhs) const
	{
		return *this.x*rhs.x + *this.y*y + *this.z*z;
	};
};


template <typename T>

struct Vec3
{
public:
	T x, y, z, w;
public:
	vec2 = default;
	Vec2(T x, T y, T z)
		:x(x),
		y(y),
		z(z)
	{};
	inline T operator +(const T& rhs) const
	{
		return Vec2(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
	};
	inline T operator -(const T& rhs) const
	{
		return Vec2(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
	};
	inline T operator *(const T& rhs) const

	{
		return Vec2(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
	};
	inline T operator *(const int& rhs) const
	{
		return Vec2(x*rhs, y*rhs, z*rhs, w*rhs.w);
	}
	inline float operator /(const T& rhs) const
	{
		return Vec2(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
	};
	inline float operator /(const int& rhs) const
	{
		return Vec2(x / rhs, y / rhs, z / rhs, w / rhs);
	};
	inline operator +=(const T& rhs)
	{
		*this = *this + rhs;
	};
	inline operator -=(const T& rhs)
	{
		*this = *this - rhs;
	};
	inline operator *=(const T& rhs)
	{
		*this = *this * rhs;
	};
	inline operator /=(const T& rhs)
	{
		*this = *this / rhs;
	};
	inline float lenSqr() const
	{
		x*x + y*y + z*z + w*w;
	}
	inline float len()
	{
		return sqrt(lenSqr());
	};
	inline normalize(const T& rhs)
	{
		const T l = len();
		return l != (T)0 ? *this * ((T)1 / l) : (T)0;
	};
	inline T dotProduct(const T& rhs) const
	{
		return *this.x*rhs.x + *this.y*y + *this.z*z + *this.w*w;
	};
};
