#pragma once
#include "maths/Matrix.h"


namespace maths {
	template <typename T>
	struct mat4 : public mat<T, 4>
	{
		//Calling parent constructor
		mat4(const T scalar = T())
			:mat<T, 3>{ scalar }
		{};
		//Matrix Rotation
		inline mat4<T> RotateX(const float rad);
		inline mat4<T> RotateY(const float rad);
		inline mat4<T> RotateZ(const float rad);

		//Predefined matrices	

		//inline mat4<float> ortho(float top, float left, float right, float bottom, float far, float near) const;
		//inline mat4<T> persp();
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

	template<typename T>
	inline mat4<T> mat4<T>::RotateX(const float rad)
	{
		return *this * RotateXMatrix<T>(rad);
	}

	template<typename T>
	inline mat4<T> mat4<T>::RotateY(const float rad)
	{
		return *this * RotateYMatrix<T>(rad);
	}

	template<typename T>
	inline mat4<T> mat4<T>::RotateZ(const float rad)
	{
		return *this * RotateZMatrix<T>(rad);
	}


	typedef mat4<int> mat4i;
	typedef mat4<float> mat4f;

}