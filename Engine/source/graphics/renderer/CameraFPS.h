#pragma once
#include "Camera.h"
#include "maths/Vector.h"
#include "maths/Matrix4.h"

namespace graphics
{
	class CameraFPS : public Camera
	{
	public:
		CameraFPS(maths::vec3f pos, float fov);
		maths::mat4f GetViewMat();
	public:
		//Euler Angles
		float yaw = -90.0f;
		float pitch = 0.0f;
		//Variable variables for camera
		float speed = 5.0f;
		float sensitivity = 0.1f;
		float zoom = 45.0f;

	private:
		void UpdateCamera();
		void UpdateLook(float x, float y);
		void UpdatePos(int keyCode, float dt);
	
	private:
		maths::vec3f right = {1.2f, 0.3f, 0.2f};
		maths::vec3f front = {0.0f, 0.0f, -1.0f};

	};
}