#pragma once
#include "Matrix.h"

namespace maths
{
	template <typename T>
	struct mat2 : public mat<T, 2>
	{
		//Calling parent constructor
		mat2(const T scalar = T())
			:mat<T, 2>{scalar}
		{};
		mat2(const mat<T, 2> rhs)
			: mat<T, 2>(rhs) {}
		
		static mat2<T> RotateMat(const T theta);
		inline mat2<T> Rotate(const float rad) const;
		inline T Det() const;
	};

	template<typename T>
	mat2<T> mat2<T>::RotateMat(const T theta)
	{
		mat2<T> ans;
		const T sinTheta = sin(theta);
		const T cosTheta = cos(theta);
		ans.elements[0] = cosTheta;
		ans.elements[1] = -sinTheta;
		ans.elements[2] = sinTheta;
		ans.elements[3] = cosTheta;
		return ans;
	}

	template<typename T>
	inline mat2<T> mat2<T>::Rotate(const float rad) const
	{
		return RotateMat(rad) * *this;
	}

	template<typename T>
	inline T mat2<T>::Det() const
	{
		return this->elements[0] * this->elements[2] - this->elements[1] * this->elements[3];
	}

	typedef mat2<int> mat2i;
	typedef mat2<float> mat2f;
		
}