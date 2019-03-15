#include "pch.h"
#include "CameraFPS.h"
#include "events/Events.h"

namespace graphics
{
	CameraFPS::CameraFPS(maths::vec3f pos, float fov)
		:Camera(pos, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f })
	{
		UpdateCamera();
	}
	maths::mat4f CameraFPS::GetViewMat()
	{
		return maths::lookAt(pos, pos + front, up);
	}

	void CameraFPS::UpdateCamera()
	{
		maths::vec3f dir;
		// Calculating direction vector
		dir.x = cos(maths::GetRadians(yaw)) * cos(maths::GetRadians(pitch));
		dir.y = sin(maths::GetRadians(pitch));
		dir.z = sin(maths::GetRadians(yaw)) * cos(maths::GetRadians(pitch));
		dir = maths::normalize(dir);

		// Crossing up and direction vector give perpendicular vector which 
		// is to the right
		right = maths::normalize(maths::cross(dir, {0.0f, 1.0f, 0.0f}));  
		up = maths::normalize(maths::cross(right, dir));

	}

	void CameraFPS::UpdateLook(float x, float y)
	{		
		// Updating pitch and yaw depending on where the mouse is
		x *= sensitivity;
		y *= sensitivity;
		yaw += x;
		pitch += y;

		if (pitch > 89.9f)
			pitch = 89.9f;
		if (pitch < -89.9f)
			pitch = -89.9f;

		UpdateCamera();
	}

	void CameraFPS::UpdatePos(int keyCode, float dt)
	{
		// Updating positing based on keybaord input
		if (keyCode == KEY_W)
			pos += front * speed * dt;
		if (keyCode == KEY_A)
			pos += front * speed * dt;
		if (keyCode == KEY_S)
			pos += right * speed * dt;
		if (keyCode == KEY_D)
			pos += right * speed * dt;
	}
}

