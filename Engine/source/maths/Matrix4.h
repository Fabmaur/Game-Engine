#pragma once
#include "maths/Matrix.h"
#include <cmath>
#include "MathsFunc.h"


namespace maths
{

	template <typename T>
	struct mat4 : public mat<T, 4>
	{
		//Calling parent constructor
		mat4(const T scalar = T())
			:mat<T, 4>{ scalar }
		{};
		mat4(const mat<T, 4> rhs)
			: mat<T, 4>(rhs) {}

		//Matrix Rotation
		static inline mat4<T> TranslateMat(const T x, const T y, const T z);
		static inline mat4<T> TranslateMat(const vec3<T> vec3);
		static inline mat4<T> RotateXMat(const T rad);
		static inline mat4<T> RotateYMat(const T rad);
		static inline mat4<T> RotateZMat(const T rad);
		static inline mat4<T> RotateMat(const T rad, const vec3<T>& axis);
		static inline mat4<T> RotateMat(const T rad, const T x, const T y, T const z);
		inline void Rotate(const T rad, const vec3<T>& axis);
		inline void Rotate(const T rad, const T x, const T y, T const z);
		inline void Translate(const T x, const T y, const T z);
		inline void Translate(const vec3<T> vec);
		inline void RotateX(const T rad);
		inline void RotateY(const T rad);
		inline void RotateZ(const T rad);
	
	};

	template <typename T>
	inline mat4<T> mat4<T>::RotateXMat(const T rad)
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
		ans.elements[6] = (T)sinTheta;
		ans.elements[7] = (T)0;
		ans.elements[8] = (T)0;
		ans.elements[9] = (T)-sinTheta;
		ans.elements[10] = (T)cosTheta;
		ans.elements[11] = (T)0;
		ans.elements[12] = (T)0;
		ans.elements[13] = (T)0;
		ans.elements[14] = (T)0;
		ans.elements[15] = (T)1;
		
		return ans;
	};
		
	template <typename T>
	inline mat4<T> mat4<T>::RotateYMat(const T rad)
	{

		const T sinTheta = sin(rad);
		const T cosTheta = cos(rad);

		mat4<T> ans;
		ans.elements[0] = (T)cosTheta;
		ans.elements[1] = (T)0;
		ans.elements[2] = (T)sinTheta;
		ans.elements[3] = (T)0;
		ans.elements[4] = (T)0;
		ans.elements[5] = (T)1;
		ans.elements[6] = (T)0;
		ans.elements[7] = (T)0;
		ans.elements[8] = (T)-sinTheta;
		ans.elements[9] = (T)0;
		ans.elements[10] = (T)cosTheta;
		ans.elements[11] = (T)0;
		ans.elements[12] = (T)0;
		ans.elements[13] = (T)0;
		ans.elements[14] = (T)0;
		ans.elements[15] = (T)1;

		return ans;
	};

	template <typename T>
	inline mat4<T> mat4<T>::RotateZMat(const T rad)
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
		ans.elements[9] = (T)0;
		ans.elements[10] = (T)0;
		ans.elements[11] = (T)0;
		ans.elements[12] = (T)0;
		ans.elements[14] = (T)0;
		ans.elements[15] = (T)1;

		return ans;
	};

	template <typename T>
	inline mat4<T> mat4<T>::RotateMat(const T rad, const vec3<T>& axis)
	{
		mat4 ans(1.0f);

		float r = GetRadians(rad);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		ans.elements[0 + 0 * 4] = x * x * omc + c;
		ans.elements[0 + 1 * 4] = y * x * omc + z * s;
		ans.elements[0 + 2 * 4] = x * z * omc - y * s;
		ans.elements[1 + 0 * 4] = x * y * omc - z * s;
		ans.elements[1 + 1 * 4] = y * y * omc + c;
		ans.elements[1 + 2 * 4] = y * z * omc + x * s;
		ans.elements[2 + 0 * 4] = x * z * omc + y * s;
		ans.elements[2 + 1 * 4] = y * z * omc - x * s;
		ans.elements[2 + 2 * 4] = z * z * omc + c;

		return ans;
	}

	template <typename T>
	inline mat4<T> mat4<T>::RotateMat(const T rad, const T x, const T y, T const z)
	{
		mat4 ans(1.0f);

		float r = GetRadians(rad);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		ans.elements[0 + 0 * 4] = x * x * omc + c;
		ans.elements[0 + 1 * 4] = y * x * omc + z * s;
		ans.elements[0 + 2 * 4] = x * z * omc - y * s;
		ans.elements[1 + 0 * 4] = x * y * omc - z * s;
		ans.elements[1 + 1 * 4] = y * y * omc + c;
		ans.elements[1 + 2 * 4] = y * z * omc + x * s;
		ans.elements[2 + 0 * 4] = x * z * omc + y * s;
		ans.elements[2 + 1 * 4] = y * z * omc - x * s;
		ans.elements[2 + 2 * 4] = z * z * omc + c;

		return ans;
	}

	template <typename T>
	static inline mat4<T> Ortho(T left, T right, T top, T bottom, T far_, T near_)
	{
		mat4<T> ans((T)1);

		ans.elements[0] = (T)2 / right - left;
		ans.elements[5] = (T)2 / top - bottom;
		ans.elements[10] = (T)-2 / far_ - near_;
		ans.elements[12] = -(right + left) / (right - left);
		ans.elements[13] = -(top + bottom) / (top - bottom);
		ans.elements[14] = -(far_ + near_) / (far_ - near_);
		ans.elements[15] = (T)1; // may be 0 or -1

		return ans;
	}

	template <typename T>
	static inline mat4<T> Perspective(T fov, T aspectRatio, T near_, T far_)
	{
		mat4<T> ans;

		float a = 1.0f / tan(GetRadians(0.5f * fov));
		
		ans.elements[0] = a / aspectRatio;
		ans.elements[5] = a;
		ans.elements[10] = (near_ + far_) / (near_ - far_);
		ans.elements[11]  = ( 2* near_ * far_) / (near_ - far_);
		ans.elements[14] = -1.0f;
		
		return ans;
		//const auto fov_rad = GetRadians(fov);
		//const auto w = (T)1.0f / std::tan(fov_rad / (T)2.0);
		//const auto h = w * aspectRatio;
		//
		//ans.elements[0] = w;
		//ans.elements[1] = (T)0.0;
		//ans.elements[2] = (T)0.0;
		//ans.elements[3] = (T)0.0;
		//ans.elements[4] = (T)0.0;
		//ans.elements[5] = h;
		//ans.elements[6] = (T)0.0;
		//ans.elements[8] = (T)0.0;
		//ans.elements[7] = (T)0.0;
		//ans.elements[8] = (T)0.0;
		//ans.elements[9] = far_ / (far_ - near_);
		//ans.elements[10] = -near_ * far_ / (far_ - near_);
		//ans.elements[11] = (T)0.0;
		//ans.elements[12] = (T)0.0;
		//ans.elements[14] = (T)1.0;
		//ans.elements[15] = (T)0.0;
		//
		//return ans;
		//
	}

	template <typename T>
	inline mat4<T> mat4<T>::TranslateMat(const T x, const T y, const T z)
	{
		mat4<T> ans((T)1);
		ans.elements[12] = x;
		ans.elements[13] = y;
		ans.elements[14] = z;

		return ans;
	}

	template <typename T>
	inline mat4<T> mat4<T>::TranslateMat(const vec3<T> vec3)
	{
		mat4<T> ans((T)1);
		ans.elements[12] = vec3.x;
		ans.elements[13] = vec3.y;
		ans.elements[14] = vec3.z;

		return ans;
	}

	template<typename T>
	inline void mat4<T>::Rotate(const T rad, const vec3<T>& axis)
	{
		*this = RotateMat(GetRadians(rad), axis) * *this;
	}

	template<typename T>
	inline void mat4<T>::Rotate(const T rad, const T x, const T y, T const z)
	{
		*this = RotateMat(GetRadians(rad), x, y, z) * *this;
	}

	template <typename T>
	inline void mat4<T>::Translate(const T x, const T y, const T z)
	{
		
		*this =  TranslateMat(x, y, z) * *this;
	}

	template <typename T>
	inline void mat4<T>::Translate(const vec3<T> vec)
	{
		*this = TranslateMat(vec) * *this;
	}
		
	template<typename T>
	inline void mat4<T>::RotateX(const T rad)
	{
		*this = RotateXMat(rad) * *this;
	}

	template<typename T>
	inline void mat4<T>::RotateY(const T rad)
	{	
		*this = RotateYMat(rad) * *this;
	}

	template<typename T>
	inline void mat4<T>::RotateZ(const T rad)
	{
		*this = RotateZMat(rad) * *this;
	}



	typedef mat4<int> mat4i;
	typedef mat4<float> mat4f;

}