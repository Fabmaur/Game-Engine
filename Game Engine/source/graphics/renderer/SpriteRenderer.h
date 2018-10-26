#pragma once
#include "graphics/renderer/Renderer.h"
#include "graphics/renderer/Sprite.h"
#include "graphics/gl_types/IndexBuffer.h"
#include "graphics/renderer/simple_shapes/Square.h"
#include <queue>

namespace graphics {
	class SpriteRenderer
	{
	public:
		SpriteRenderer(const Shader& shader);
		void Enqueue(const Sprite& sprite);
		void Dequeue();


	private:
		std::queue<Sprite> renderObjects;
		graphics::IndexBuffer IBO;
		graphics::Shader shader;
	};
}