#pragma once
#include "maths/Matrix.h"

namespace maths
{

	
	template <typename T>
	struct mat3 : public mat<T, 3>
	{
		//Calling parent constructor
		mat3(const T scalar = T())
			:mat<T, 3>{ scalar }
		{};
		mat3(const mat<T, 3> rhs)
			: mat<T, 3>(rhs) {}

		//Matrix Rotation
		static mat3<T> RotateXMatrix(const float rad);
		static mat3<T> RotateYMatrix(const float rad);
		static mat3<T> RotateZMatrix(const float rad);
		inline mat3<T> RotateX(const float rad);
		inline mat3<T> RotateY(const float rad);
		inline mat3<T> RotateZ(const float rad);
	};

	template<typename T>
	mat3<T> mat3<T>::RotateXMatrix(const float rad)
	{
		mat3<T> ans;
		const T sinTheta = sin(rad);
		const T cosTheta = cos(rad);
		ans.elements[0] = (T)1;
		ans.elements[1] = (T)0;
		ans.elements[2] = (T)0;
		ans.elements[3] = (T)0;
		ans.elements[4] = (T)cosTheta;
		ans.elements[5] = (T)-sinTheta;
		ans.elements[6] = (T)0;
		ans.elements[7] = (T)sinTheta;
		ans.elements[8] = (T)cosTheta;
		return ans;
	}
	
	template<typename T>
	mat3<T> mat3<T>::RotateYMatrix(const float rad)
	{
		mat3<T> ans;
		const T sinTheta = sin(rad);
		const T cosTheta = cos(rad);
		ans.elements[0] = (T)cosTheta;
		ans.elements[1] = (T)0;
		ans.elements[2] = (T)sinTheta;
		ans.elements[3] = (T)0;
		ans.elements[4] = (T)1;
		ans.elements[5] = (T)0;
		ans.elements[6] = (T)-sinTheta;
		ans.elements[7] = (T)0;
		ans.elements[8] = (T)cosTheta;
		return ans;
	}
	
	template<typename T>
	mat3<T> mat3<T>::RotateZMatrix(const float rad)
	{
		mat3<T> ans;
		const T sinTheta = sin(rad);
		const T cosTheta = cos(rad);
		ans.elements[0] = (T)cosTheta;
		ans.elements[1] = (T)sinTheta;
		ans.elements[2] = (T)0;
		ans.elements[3] = (T)-sinTheta;
		ans.elements[4] = (T)cosTheta;
		ans.elements[5] = (T)0;
		ans.elements[6] = (T)0;
		ans.elements[7] = (T)0;
		ans.elements[8] = (T)1;
		return ans;
	}
	
	template<typename T>
	inline mat3<T> mat3<T>::RotateX(const float rad)
	{
		return RotateXMatrix(rad) * *this;
	}
	template<typename T>
	inline mat3<T> mat3<T>::RotateY(const float rad)
	{
		return RotateYMatrix(rad) * *this;
	}
	template<typename T>
	inline mat3<T> mat3<T>::RotateZ(const float rad)
	{
		return RotateZMatrix(rad) * *this;
	}

	typedef mat3<int> mat3i;
	typedef mat3<float> ma3f;
}