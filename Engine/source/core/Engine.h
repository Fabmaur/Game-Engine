
#pragma once
#include <GL/glew.h>
#include "graphics/renderer/window.h"
#include "graphics/gl_types/Buffers.h"
#include "graphics/simple_shapes/Shapes.h"
#include "graphics/renderer/Texture.h"
#include "graphics/renderer/Shader.h"
#include "maths/maths.h"

namespace core {
	class Engine {
	public:
		Engine(const int width = 800, const int height = 600);
		Engine(const char* title, const int width = 800, const int height = 600);

		void Start();
		void Stop();

	private:
		graphics::Window window;
		
	};
}