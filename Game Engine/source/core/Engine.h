#pragma once
#include <GL/glew.h>
#include "graphics/renderer/window.h"
#include "graphics/gl_types/Buffers.h"
#include "graphics/renderer/simple_shapes/Shapes.h"
#include "graphics/renderer/SpriteRenderer.h"
#include "graphics/renderer/Sprite.h"

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