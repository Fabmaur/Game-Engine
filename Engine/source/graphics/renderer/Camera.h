#pragma once
#include "maths/maths.h"

namespace graphics
{
	/*FPS camera used to look around.*/

	class Camera
	{
	public:
		Camera();

	private:
		maths::vec3f pos;
		maths::vec3f target;
		maths::vec3f up;
	};
}