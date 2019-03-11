#include "pch.h"
#include "CameraFPS.h"

namespace graphics
{
	CameraFPS::CameraFPS(maths::vec3f pos, float fov, float aspectRatio, float zNear, float zFar)
		:Camera(pos, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }),
		perspective(maths::Perspective(fov, aspectRatio, zNear, zFar))
	{}


	maths::mat4f CameraFPS::GetViewMat()
	{
		return maths::lookAt(pos, pos + front, up);
	}

}

