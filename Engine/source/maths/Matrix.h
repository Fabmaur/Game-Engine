#pragma once
#include "Vector.h"

namespace maths 
{

	/* Matrix Base Class 
	using column major layout
	__     __
	|m0 m3 m6|
	|m1 m4 m7|  
	|m2 m5 m8|
	|__    __|
	*/

	////////////////
	//Decleration
	////////////////

	// Templates for the width of the matrix and the type
	template <typename T, int width>
	struct mat
	{
		// Creating an array the size of the matrix
		static const int cells = width * width;
		T elements[cells];

		//Constructors
		mat(const T Scalar = T());
		mat(const T* pointer);
		//Matrix operators
		inline mat<T, width> operator+(const mat<T, width>& rhs) const;
		inline mat<T, width> operator-(const mat<T, width>& rhs) const;
		inline mat<T, width> operator*(const mat<T, width>& rhs) const;
		inline mat<T, width> operator*(const T& scale) const;
		inline void operator=(const mat<T, width>& rhs);
		inline void operator+=(const mat<T, width>& rhs);
		inline void operator-=(const mat<T, width>& rhs);
		inline void operator*=(const mat<T, width>& rhs);
		inline void operator*=(const T& scale);

	};

	////////////////
	//Implementation
	////////////////

	template<typename T, int width>
	inline mat<T, width>::mat(const T scalar)
	{
		// Creating a scaling matrix
		for (int i = 0; i < cells; i++)
			/*Checking if the element is in the middle diagonal an if so assigning the 
			element to the scalar, otherwise elemnent is assigned to 0 */
			((i % (width+1)) == 0) ? (elements[i] = (T)1 * scalar)  : (elements[i] = (T)0);
	}

	template<typename T, int width>
	inline mat<T, width>::mat(const T* pointer)
	{
		// Recieves an array of type T and assigns it to the matrix
		for (int i = 0; i < cells; i++)
			elements[i] = pointer + i;
	}


	template<typename T, int width>
	inline mat<T, width> mat<T, width>::operator+(const mat<T, width>& rhs) const
	{
		// Goes through all the elements in matrix and adds corresponding value from rhs
		mat<T, width> ans;
		for (int i = 0; i < cells; i++)
			ans.elements[i] = elements[i] + rhs.elements[i];
		return ans;
	}

	template<typename T, int width>
	inline mat<T, width> mat<T, width>::operator-(const mat<T, width>& rhs) const
	{
		// Goes through all the elements in matrix and takes away corresponding value from rhs
		mat<T, width> ans;
		for (int i = 0; i < cells; i++)
			ans.elements[i] = elements[i] - rhs.elements[i];
		return ans;
	}

	template<typename T, int width>
	inline mat<T, width> mat<T, width>::operator*(const mat<T, width>& rhs) const
	{

		// Described in documented design
		mat<T, width> ans;
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
	inline mat<T, width> mat<T, width>::operator*(const T & scale) const
	{
		// Going through all elements and multiplying by scalar
		mat<T, width> ans;
		for (int i = 0; i < cells; i++)
			ans.elements[i] = elements[i] * scale;
		return ans;
	}

	template<typename T, int width>
	inline  void mat<T, width>::operator=(const mat<T, width>& rhs)
	{
		// Assigning lhs to rhs
		for (int i = 0; i < cells; i++)
			elements[i] = rhs.elements[i];
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

	template<typename T, int width>
	inline void mat<T, width>::operator*=(const T & scale)
	{
		*this = *this * scale;
	}
}