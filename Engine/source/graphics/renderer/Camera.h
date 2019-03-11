#pragma once
#include "maths/maths.h"

namespace graphics
{
	/*FPS camera used to look around.*/

	class Camera
	{
	public:
		Camera(maths::vec3f pos, maths::vec3f forward, maths::vec3f up)
			:pos(pos),
			forward(forward),
			up(up)
		{}

	protected:
		maths::mat4f perspectiveProj;
		maths::vec3f pos;
		maths::vec3f forward;
		maths::vec3f up;
	};
}