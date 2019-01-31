#pragma once
#include "Renderer2D.h"

#include "Sprite.h"
#include "graphics/renderer/Shader.h"
#include "maths/maths.h"
#include <deque>

namespace graphics
{
	/*Derived class of renderer - used to render sprites and shapes*/

	class SpriteRenderer : public Renderer2D
	{
	public:
		void Push(const Renderable2D* sprite)  override;
		void Flush()  override;
		void DrawSquare(graphics::Shader& shader, maths::vec3f pos , maths::vec3f size); // colour must be defined via a uniform
		void DrawTriangle(graphics::Shader& shader, maths::vec3f pos1, maths::vec3f pos2, maths::vec3f pos3);
		void DrawLine(maths::vec3f pos1, maths::vec3f pos2);
		void DrawShape(void* vertices, unsigned int vertexNum, graphics::Shader& shader);
 		void DrawCircle(const graphics::Shader& shader, const float radius);

	private:
		std::deque<const Sprite*> spriteQueue;

	};
}
