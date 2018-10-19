#pragma once
#include "Vector.h"

namespace maths {
	
	template <typename T>
	struct mat2
	{
		/* Union used to store matrix 
		as both array of elements and vectors*/
		union
		{
			T elements[2 * 2];
			vec2<T> rows[2];
		};
		//Constructors
		mat2();
		mat2(T& m0, T& m1, T& m2, T& m3);
		mat2(vec2<T>& row0, vec2<T>& row1);
		mat2(const T*);
		//Matrix operators
		inline T operator+(mat2<T>& rhs) const;
		inline T operator-(mat2<T>& rhs) const;
		inline T operator*(mat2<T>& rhs) const;
		inline T operator+=(mat2<T>& rhs);
		inline T operator-=(mat2<T>& rhs);
		inline T operator*=(mat2<T>& rhs) const;
		//Predefined matrices	
		static mat2<T> identity(T scalar = (T)1);
		static mat2<T> RotateMatrix(T theta);
		//Matrix Rotation
		inline mat2<T> Rotate(const float rad) const;
		//Matrix Maths functions
		inline T Det() const;
	};

	template <typename T>
	struct mat3
	{
		/* Union used to store matrix
		as both array of elements and vectors*/
		union
		{
			T elements[3 * 3];
			Vec3<T> rows[3];
		};
		//Constructors
		mat3();
		mat3(T& m0, T& m1, T& m2, T& m3, T& m4, T& m5, T& m6, T& m7, T& m8);
		mat3(vec3<T>& row0, vec3<T>& row1, vec3<T>& row2);
		mat3(const T*);
		//Matrix operators
		inline T operator+(mat3<T>& rhs) const;
		inline T operator-(mat3<T>& rhs) const;
		inline T operator*(mat3<T>& rhs) const;
		inline T operator+=(mat3<T>& rhs);
		inline T operator-=(mat3<T>& rhs);
		inline T operator*=(mat3<T>& rhs);
		//Predefined matrices	
		static mat3<T> identity(T scalar = (T)1);
		static mat3<T> RotateXMatrix(const float rad) const;
		static mat3<T> RotateYMatrix(const float rad) const;
		static mat3<T> RotateZMatrix(const float rad) const;
		//Matrix Rotation
		inline mat3<T> RotateX(const float rad);
		inline mat3<T> RotateY(const float rad);
		inline mat3<T> RotateZ(const float rad);
		//Matrix Maths functions
		inline T Det() const;
	};

	template <typename T>
	struct mat4
	{
		/* Union used to store matrix
		as both array of elements and vectors*/
		union
		{
			T elements[4 * 4];
			Vec4<T> rows[4];
		};
		//Constructors
		mat4();
		mat4(T& m0, T& m1, T& m2, T& m3, T& m4, T& m5, T& m6, T& m7, T& m8,
			T& m9, T& m10, T& m11, T& m12, T& m13, T& m14, T& m15);
		mat4(vec4<T>& row0, vec4<T>& row1, vec4<T>& row2, vec4<T>& row3);
		mat4(const T*);
		//Matrix operators
		inline T operator+(mat4<T>& rhs) const;
		inline T operator-(mat4<T>& rhs) const;
		inline T operator*(mat4<T>& rhs) const;
		inline T operator+=(mat4<T>& rhs);
		inline T operator-=(mat4<T>& rhs);
		inline T operator*=(mat4<T>& rhs);
		//Predefined matrices	
		static mat4<T> identity(T scalar = (T)1);
		inline mat4<T> RotateXMatrix(const float rad) const;
		inline mat4<T> RotateYMatrix(const float rad) const;
		inline mat4<T> RotateZMatrix(const float rad) const;
		inline mat4<float> ortho(float top, float left, float right, float bottom, float far, float near) const;
		inline mat4<T> persp();
		//Matrix Rotation
		inline mat4<T> RotateX(const float rad);
		inline mat4<T> RotateY(const float rad);
		inline mat4<T> RotateZ(const float rad);
		//Matrix Maths functions
		inline T Det() const;
	};
}