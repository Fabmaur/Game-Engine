#include "maths/matrix.h"

using namespace maths;


///////////////////////////////
// mat2
///////////////////////////////
template <typename T>
mat2<T>::mat2() 
{
	for(int i = 0; i < sizeof(elements)/sizeof(T); i++)
		elements[i] = (T)0;
}

template <typename T>
mat2<T>::mat2(T& m0, T& m1, T& m2, T& m3)
{
	elements[0] = m0;
	elements[1] = m1;
	elements[2] = m2;
	elements[3] = m3;
}

template <typename T>
mat2<T>::mat2(vec2<T>& row0, vec2<T>& row1)
{
	rows[0] = row0;
	rows[1] = row1;
}

template <typename T>
mat2<T>::mat2(const T* pointer)
{
	for (int i = 0; i < 4; i++)
		elements[i] = pointer + i;
}

template<typename T>
inline T mat2<T>::operator+(mat2<T>& rhs) const
{
	mat2<T> ans;
	for (int i = 0; i < sizeof(elements) / sizeof(T); i++)
		ans.elements[i] = elements[i] + rhs.elements[i];
	return ans;
}


template<typename T>
inline T mat2<T>::operator-(mat2<T>& rhs) const
{
	mat2<T> ans;
	for (int i = 0; i < sizeof(elements) / sizeof(T); i++)
		ans.elements[i] = elements[i] - rhs.elements[i];
	return ans;
}

template<typename T>
inline T mat2<T>::operator*(mat2<T>& rhs) const
{
	mat2 ans;
	
	for (int y = 0; y < sizeof(elements) / sizeof(T); y++)
	{
		elementSum = T(0)
		for (int x = 0; x < sizeof(elements) / sizeof(T); i++) {
			for (int f = 0; f sizeof(elements) / sizeof(T); f++) {
				f += elements[x + f * sizeof(rows) / sizeof(T)] + rhs.elements[f + y * sizeof(rows) / sizeof(T)];
			}
			ans.elements[x + y * sizeof(rows) / sizeof(T)]] = elementSum;
		}
	}
	return ans;
	
}

template<typename T>
inline T maths::mat2<T>::operator+=(mat2<T>& rhs)
{
	return *this = *this + rhs;
}

template<typename T>
inline T maths::mat2<T>::operator-=(mat2<T>& rhs)
{
	return *this = *this - rhs;
}

template<typename T>
inline T maths::mat2<T>::operator*=(mat2<T>& rhs) const
{
	*this = *this * rhs;
}

template<typename T>
mat2<T> mat2<T>::identity(T scalar)
{
	elements[0] = (T)1 * scalar;
	elements[1] = (T)0 * scalar;
	elements[2] = (T)1 * scalar;
	elements[3] = (T)0 * scalar;
}

template<typename T>
mat2<T> mat2<T>::RotateMatrix(T theta)
{
	const T sinTheta = sin(theta);
	const T cosTheta = cos(theta);
	return { cosTheta, sinTheta,
			-sinTheta, cosTheta };
}

template<typename T>
inline mat2<T> maths::mat2<T>::Rotate(const float rad) const
{
	return RotateMatrix(rad) * *this;
}

template<typename T>
T mat2<T>::Det() const
{
	return elements[0]*elements[3] - elements[1]*elements[2];
}
///////////////////////////////
// mat3
///////////////////////////////

template <typename T>
mat3<T>::mat3()
{
	for (int i = 0; i < sizeof(elements) / sizeof(T); i++)
		elements[i] = (T)0;
}

template <typename T>
mat3<T>::mat3(T& m0, T& m1, T& m2, T& m3, T& m4, T& m5, T& m6, T& m7, T& m8)
{
	elements[0] = m0;
	elements[1] = m1;
	elements[2] = m2;
	elements[3] = m3;
	elements[4] = m4;
	elements[5] = m5;
	elements[6] = m6;
	elements[7] = m7;
	elements[8] = m8;
}

template <typename T>
mat3<T>::mat3(vec3<T>& row0, vec3<T>& row1, vec3<T>& row2)
{
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
}

template <typename T>
mat3<T>::mat3(const T* pointer)
{
	for (int i = 0; i < 9; i++)
		elements[i] = pointer + i;
}


template<typename T>
inline T mat3<T>::operator+(mat3<T>& rhs) const
{
	mat3<T> ans;
	for (int i = 0; i < sizeof(elements) / sizeof(T); i++)
		ans.elements[i] = elements[i] + rhs.elements[i];
	return ans;
}


template<typename T>
inline T mat3<T>::operator-(mat3<T>& rhs) const
{
	mat3<T> ans;
	for (int i = 0; i < sizeof(elements) / sizeof(T); i++)
		ans.elements[i] = elements[i] - rhs.elements[i];
	return ans;
}

template<typename T>
inline T mat3<T>::operator*(mat3<T>& rhs) const
{
	mat3 ans;

	for (int y = 0; y < sizeof(elements) / sizeof(T); y++)
	{
		elementSum = T(0)
			for (int x = 0; x < sizeof(elements) / sizeof(T); i++) {
				for (int f = 0; f sizeof(elements) / sizeof(T); f++) {
					f += elements[x + f * sizeof(rows) / sizeof(T)] + rhs.elements[f + y * sizeof(rows) / sizeof(T)];
				}
				ans.elements[x + y * sizeof(rows) / sizeof(T)]] = elementSum;
			}
	}
	return ans;

}

template<typename T>
inline T maths::mat3<T>::operator+=(mat3<T>& rhs)
{
	return *this = *this + rhs;
}

template<typename T>
inline T maths::mat3<T>::operator-=(mat3<T>& rhs)
{
	return *this = *this - rhs;
}

template<typename T>
inline T mat3<T>::operator*=(mat3<T>& rhs)
{
	*this = *this * rhs;
}

template<typename T>
mat3<T> mat3<T>::identity(T scalar)
{
	elements[0] = (T)1 * scalar;
	elements[1] = (T)0 * scalar;
	elements[2] = (T)0 * scalar;
	elements[3] = (T)0 * scalar;
	elements[4] = (T)1 * scalar;
	elements[5] = (T)0 * scalar;
	elements[6] = (T)0 * scalar;
	elements[7] = (T)0 * scalar;
	elements[8] = (T)1 * scalar;
	
}

template<typename T>
inline mat3<T> mat3<T>::RotateXMatrix(const float rad) const
{
	const T sinTheta = sin(rad);
	const T cosTheta = cos(rad);
	return {(T)1, (T)0, (T)0, (T)0, cosTheta, -sinTheta, T(0), sinTheta, cosTheta};
}

template<typename T>
inline mat3<T> mat3<T>::RotateYMatrix(const float rad) const
{
	const T sinTheta = sin(rad);
	const T cosTheta = cos(rad);
	return {cosTheta, (T)0, sinTheta, (T)0, (T)1, (T)0, (T)-sinTheta, (T)0, (T)cosTheta };
}

template<typename T>
inline mat3<T> mat3<T>::RotateZMatrix(const float rad) const
{
	const T sinTheta = sin(rad);
	const T cosTheta = cos(rad);
	return {(TcosTheta, (T)sinTheta, 0, (T)-sinTheta, (T)cosTheta, (T)0, (T)0, (T)1 };
}

template<typename T>
inline mat3<T> maths::mat3<T>::RotateX(const float rad)
{
	return *this * RotateXMatrix;
}

template<typename T>
inline mat3<T> maths::mat3<T>::RotateY(const float rad)
{
	return *this * RotateYMatrix;
}

template<typename T>
inline mat3<T> maths::mat3<T>::RotateZ(const float rad)
{
	return *this * RotateYMatrix;
}


template<typename T>
T mat3<T>::Det() const
{
	return T(false);
}

///////////////////////////////
// mat4
///////////////////////////////

template <typename T>
mat4<T>::mat4()
{
	for (int i = 0; i < sizeof(elements) / sizeof(T); i++)
		elements[i] = (T)0;
}

template <typename T>
mat4<T>::mat4(T& m0, T& m1, T& m2, T& m3, T& m4, T& m5, T& m6, T& m7, T& m8,
			T& m9, T& m10, T& m11, T& m12, T& m13, T& m14, T& m15)
{
	elements[0] = m0;
	elements[1] = m1;
	elements[2] = m2;
	elements[3] = m3;
	elements[4] = m4;
	elements[5] = m5;
	elements[6] = m6;
	elements[7] = m7;
	elements[8] = m8;
	elements[9] = m9;
	elements[10] = m10;
	elements[11] = m11;
	elements[12] = m12;
	elements[13] = m13;
	elements[14] = m14;
	elements[15] = m15;
}

template <typename T>
mat4<T>::mat4(vec4<T>& row0, vec4<T>& row1, vec4<T>& row2, vec4<T>& row3)
{
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
	rows[3] = row3;
}

template <typename T>
mat4<T>::mat4(const T* pointer)
{
	for (int i = 0; i < 15; i++)
		elements[i] = pointer + i;
}


template<typename T>
inline T mat4<T>::operator+(mat4<T>& rhs) const
{
	mat3<T> ans;
	for (int i = 0; i < sizeof(elements) / sizeof(T); i++)
		ans.elements[i] = elements[i] + rhs.elements[i];
	return ans;
}


template<typename T>
inline T mat4<T>::operator-(mat4<T>& rhs) const
{
	mat4<T> ans;
	for (int i = 0; i < sizeof(elements) / sizeof(T); i++)
		ans.elements[i] = elements[i] - rhs.elements[i];
	return ans;
}

template<typename T>
inline T mat4<T>::operator*(mat4<T>& rhs) const
{
	mat3 ans;

	for (int y = 0; y < sizeof(elements) / sizeof(T); y++)
	{
		elementSum = T(0)
			for (int x = 0; x < sizeof(elements) / sizeof(T); i++) {
				for (int f = 0; f sizeof(elements) / sizeof(T); f++) {
					f += elements[x + f * sizeof(rows) / sizeof(T)] + rhs.elements[f + y * sizeof(rows) / sizeof(T)];
				}
				ans.elements[x + y * sizeof(rows) / sizeof(T)]] = elementSum;
			}
	}
	return ans;

}

template<typename T>
inline T mat4<T>::operator+=(mat4<T>& rhs)
{
	return *this = *this + rhs;
}

template<typename T>
inline T mat4<T>::operator-=(mat4<T>& rhs)
{
	return *this = *this - rhs;
}

template<typename T>
inline T mat4<T>::operator*=(mat4<T>& rhs)
{
	*this = *this * rhs;
}

template<typename T>
mat4<T> mat4<T>::identity(T scalar)
{
	elements[0] = (T)1 * scalar;
	elements[1] = (T)0 * scalar;
	elements[2] = (T)0 * scalar;
	elements[3] = (T)0 * scalar;
	elements[4] = (T)0 * scalar;
	elements[5] = (T)1 * scalar;
	elements[6] = (T)0 * scalar;
	elements[7] = (T)0 * scalar;
	elements[8] = (T)0 * scalar;
	elements[9] = (T)0 * scalar;
	elements[10] = (T)1 * scalar;
	elements[11] = (T)0 * scalar;
	elements[12] = (T)0 * scalar;
	elements[13] = (T)0 * scalar;
	elements[14] = (T)0 * scalar;
	elements[15] = (T)1 * scalar;

}

template<typename T>
inline mat4<T> mat4<T>::RotateXMatrix(const float rad) const
{
	const T sinTheta = sin(rad);
	const T cosTheta = cos(rad);
	return { (T)1, (T)0, (T)0, (T)0, (T)0,  cosTheta, -sinTheta, T(0), (T)0, sinTheta, cosTheta, (T)0, (T)0, (T)0, (T)0 (T)1 };
}

template<typename T>
inline mat4<T> mat4<T>::RotateYMatrix(const float rad) const
{
	const T sinTheta = sin(rad);
	const T cosTheta = cos(rad);
	return return { cosTheta, (T)0, -sinTheta, (T)0, (T)0,  (T) 1, (T)0, T(0), sinTheta, (T)0 cosTheta,(T)0, (T)0, (T)0, (T)0 (T)1 };
}

template<typename T>
inline mat4<T> mat4<T>::RotateZMatrix(const float rad) const
{
	const T sinTheta = sin(rad);
	const T cosTheta = cos(rad);
	return return { cosTheta, sinTheta, (T)0, (T)0, -sinTheta, cosTheta, T(0), T(0), (T)0, T(0), (T)1, (T)0, (T)0, (T)0, (T)0, (T)1 };
}

template<typename T>
inline mat4<T> mat4<T>::RotateX(const float rad)
{
	return *this * RotateXMatrix;
}

template<typename T>
inline mat4<T> mat4<T>::RotateY(const float rad)
{
	return *this * RotateYMatrix;
}

template<typename T>
inline mat4<T> mat4<T>::RotateZ(const float rad)
{
	return *this * RotateYMatrix;
}

inline mat4<float> mat4<float>::ortho(float top, float left, float right, float bottom, float far, float near) const
{
	return { (1.0f / right - left), 0.0f, 0.0f, 0.0f, 0.0f, (2 / top - bottom), 0.0f, 0.0f, 0.0f, 0.0f,
		(-2/far - near), 0.0f, -(right + left)/(right - left), -(top + bottom)/(top - bottom), -(far + near)/(far -near), 1.0f};
}

template<typename T>
inline mat4<T> maths::mat4<T>::persp()
{
	return (T)false;
}

template<typename T>
inline mat3<T> maths::mat3<T>::RotateX(const float rad)
{
	return *this * RotateXMatrix;
}

template<typename T>
inline mat3<T> maths::mat3<T>::RotateY(const float rad)
{
	return *this * RotateYMatrix;
}

template<typename T>
inline mat3<T> maths::mat3<T>::RotateZ(const float rad)
{
	return *this * RotateYMatrix;
}

template<typename T>
T mat4<T>::Det() const
{
	return (T)false;
}