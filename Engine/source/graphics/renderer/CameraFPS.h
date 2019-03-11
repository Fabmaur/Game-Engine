#pragma once
#include "Camera.h"
#include "maths/Vector.h"
#include "maths/Matrix4.h"

namespace graphics
{
	const float YAW = -90.0f;
	const float PITCH = 0.0f;
	const float SPEED = 5.0f;
	const float SENSITIVITY = 0.1f;
	const float ZOOM = 45.0f;

	class CameraFPS : public Camera
	{
	public:
		CameraFPS(maths::vec3f pos, float fov, float aspectRatio, float zNear, float zFar);
		maths::mat4f GetViewMat();
	private:
		maths::mat4f perspective;
		maths::vec3f right;
		maths::vec3f front;

	};
}