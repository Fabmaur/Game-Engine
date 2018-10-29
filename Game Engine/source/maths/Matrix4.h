#pragma once
#include "maths/Matrix.h"


namespace maths {
	template <typename T>
	struct mat4 : public mat<T, 4>
	{
		//Calling parent constructor
		mat4(const T scalar = T())
			:mat<T, 4>{ scalar }
		{};
		mat4(const mat<T, 4>& rhs)
			: mat<T, 4>(rhs) {}

		//Matrix Rotation
		inline void Translate(const T x, const T y, const T z);
		inline void Translate(const vec3<T> vec);
		inline void RotateX(const float rad);
		inline void RotateY(const float rad);
		inline void RotateZ(const float rad);
	
	};

	template <typename T>
	static inline mat4<T> RotateXMatrix(const float rad)
	{
		
		const T sinTheta = sin(rad);
		const T cosTheta = cos(rad);

		mat4<T> ans;
		ans.elements[0] = (T)1;
		ans.elements[1] = (T)0;
		ans.elements[2] = (T)0;
		ans.elements[3] = (T)0;
		ans.elements[4] = (T)0;
		ans.elements[5] = (T)cosTheta;
		ans.elements[6] = (T)-sinTheta;
		ans.elements[7] = (T)0;
		ans.elements[8] = (T)0;
		ans.elements[9] = (T)sinTheta;
		ans.elements[10] = (T)cosTheta;
		ans.elements[11] = (T)0;
		ans.elements[12] = (T)0;
		ans.elements[13] = (T)0;
		ans.elements[14] = (T)0;
		ans.elements[15] = (T)1;
		
		return ans;
	};
		
	template <typename T>
	static inline mat4<T> RotateYMatrix(const float rad)
	{

		const T sinTheta = sin(rad);
		const T cosTheta = cos(rad);

		mat4<T> ans;
		ans.elements[0] = (T)cosTheta;
		ans.elements[1] = (T)0;
		ans.elements[2] = (T)-sinTheta;
		ans.elements[3] = (T)0;
		ans.elements[4] = (T)0;
		ans.elements[5] = (T)1;
		ans.elements[6] = (T)0;
		ans.elements[8] = (T)0;
		ans.elements[7] = (T)sinTheta;
		ans.elements[8] = (T)0;
		ans.elements[9] = (T)cosTheta;
		ans.elements[10] = (T)0;
		ans.elements[11] = (T)0;
		ans.elements[12] = (T)0;
		ans.elements[14] = (T)0;
		ans.elements[15] = (T)1;

		return ans;
	};

	template <typename T>
	static inline mat4<T> RotateZMatrix(const float rad)
	{

		const T sinTheta = sin(rad);
		const T cosTheta = cos(rad);

		mat4<T> ans;
		ans.elements[0] = (T)cosTheta;
		ans.elements[1] = (T)sinTheta;
		ans.elements[2] = (T)0;
		ans.elements[3] = (T)0;
		ans.elements[4] = (T)-sinTheta;
		ans.elements[5] = (T)cosTheta;
		ans.elements[6] = (T)0;
		ans.elements[8] = (T)0;
		ans.elements[7] = (T)0;
		ans.elements[8] = (T)0;
		ans.elements[9] = (T)1;
		ans.elements[10] = (T)0;
		ans.elements[11] = (T)0;
		ans.elements[12] = (T)0;
		ans.elements[14] = (T)0;
		ans.elements[15] = (T)1;

		return ans;
	};

	template <typename T>
	static inline mat4<T> Ortho(T left, T right, T top, T bottom, T far, T near)
	{
		mat4<T> ans(0);

		ans.elements[0] = (T)2 / right - left;
		ans.elements[5] = (T)2 / top - bottom;
		ans.elements[10] = (T)-2 / far - near;
		ans.elements[12] = -(right + left) / (right - left);
		ans.elements[13] = -(top + bottom) / (top - bottom);
		ans.elements[14] = -(far + near) / (far - near);
		ans.elements[15] = (T)1;

		return ans;
	}

	template <typename T>
	static inline mat4<T> Perspective(T left, T right, T top, T bottom, T far, T near)
	{
		mat4<T> ans(0);

		ans.elements[0] = (T)2 / right - left;
		ans.elements[5] = (T)2 / top - bottom;
		ans.elements[10] = (T)-2 / far - near;
		ans.elements[12] = -(right + left) / (right - left);
		ans.elements[13] = -(top + bottom) / (top - bottom);
		ans.elements[14] = -(far + near) / (far - near);
		ans.elements[15] = (T)1;

		return ans;
	}

	template <typename T>
	static inline mat4<T> TranslateMat(const T x, const T y, const T z)
	{
		mat4<T> ans(1);
		ans.elements[12] = x;
		ans.elements[13] = y;
		ans.elements[14] = z;

		return ans;
	}

	template <typename T>
	static inline mat4<T> TranslateMat(vec3<T> vec3)
	{
		mat4<T> ans(1);
		ans.elements[12] = vec3.x;
		ans.elements[13] = vec3.y;
		ans.elements[14] = vec3.z;

		return ans;
	}

	template <typename T>
	inline void mat4<T>::Translate(const T x, const T y, const T z)
	{
		*this = *this * TranslateMat<T>(x, y, z);
	}

	template <typename T>
	inline void mat4<T>::Translate(const vec3<T> vec)
	{
		*this = *this * TranslateMat<T>(vec);
	}
		
	template<typename T>
	inline void mat4<T>::RotateX(const float rad)
	{
		*this = *this * RotateXMatrix<T>(rad);
	}

	template<typename T>
	inline void mat4<T>::RotateY(const float rad)
	{
		*this = *this * RotateYMatrix<T>(rad);
	}

	template<typename T>
	inline void mat4<T>::RotateZ(const float rad)
	{
		*this = *this * RotateZMatrix<T>(rad);
	}

	typedef mat4<int> mat4i;
	typedef mat4<float> mat4f;

}