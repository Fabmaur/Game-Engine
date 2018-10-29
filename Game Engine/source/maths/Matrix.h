#pragma once
#include "Vector.h"

namespace maths {

	/* Matrix Parent Class Template
	using row major layout
	__     __
	|m0 m3 m6|
	|m1 m4 m7|  
	|m2 m5 m8|
	|__    __|
	*/
	


	////////////////
	//DECLERATION
	////////////////

	template <typename T, int width>
	struct mat
	{
		
		static const int cells = width * width;
		T elements[cells];

		//Constructors
		mat(const T Scalar = T());
		mat(const T* pointer);
		//Matrix operators
		inline mat<T, width> operator+(const mat<T, width>& rhs) const;
		inline mat<T, width> operator-(const mat<T, width>& rhs) const;
		inline mat<T, width> operator*(const mat<T, width>& rhs) const;
		inline void operator=(const mat<T, width>& rhs);
		inline void operator+=(const mat<T, width>& rhs);
		inline void operator-=(const mat<T, width>& rhs);
		inline void operator*=(const mat<T, width>& rhs);

	};

	////////////////
	//IMPLEMENTATION
	////////////////

	template<typename T, int width>
	inline mat<T, width>::mat(const T scalar)
	{
		for (int i = 0; i < cells; i++)
			((i % (width+1)) == 0) ? (elements[i] = (T)1 * scalar)  : (elements[i] = (T)0);
	}

	template<typename T, int width>
	inline mat<T, width>::mat(const T* pointer)
	{
		for (int i = 0; i < cells; i++)
			elements[i] = pointer + i;
	}


	template<typename T, int width>
	inline mat<T, width> mat<T, width>::operator+(const mat<T, width>& rhs) const
	{
		mat<T, width> ans;
		for (int i = 0; i < cells; i++)
			ans.elements[i] = elements[i] + rhs.elements[i];
		return ans;
	}

	template<typename T, int width>
	inline mat<T, width> mat<T, width>::operator-(const mat<T, width>& rhs) const
	{
		mat<T, width> ans;
		for (int i = 0; i < cells; i++)
			ans.elements[i] = elements[i] - rhs.elements[i];
		return ans;
	}

	template<typename T, int width>
	inline mat<T, width> mat<T, width>::operator*(const mat<T, width>& rhs) const
	{
		mat<T, 4> ans;

		for (int y = 0; y < width; y++)
		{
			for (int x = 0; x < width; x++) {
				T elementSum = T(0);
				for (int f = 0; f < width; f++) {
					elementSum += elements[x + f * width] * rhs.elements[f + y * width];
				}
				ans.elements[x + y * width] = elementSum;
			}
		}
		return ans;

	}

	template<typename T, int width>
	inline void mat<T, width>::operator=(const mat<T, width>& rhs)
	{
		for (int i = 0; i < cells; i++)
			this->elements[i] = rhs.elements[i];
	}


	template<typename T, int width>
	inline void mat<T, width>::operator+=(const mat<T, width>& rhs)
	{
		this = *this + rhs;
	}

	template<typename T, int width>
	inline void mat<T, width>::operator-=(const mat<T, width>& rhs)
	{
		this = *this - rhs;
	}

	template<typename T, int width>
	inline void mat<T, width>::operator*=(const mat<T, width>& rhs)
	{
		this = *this * rhs;
	}

	
}