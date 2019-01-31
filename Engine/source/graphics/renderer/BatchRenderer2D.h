#pragma once
#include "Renderer2D.h"
#include "Shader.h"
#include "graphics/renderer/Renderable2D.h"
#include "graphics/gl_types/Buffers.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Texture.h"
#include "graphics/simple_shapes/Shape.h"
#include "maths/Vector.h"

namespace graphics
{
	/*Batch renderer which can be used to render 2D sprites and shapes*/
	//Will only work with shapes at the start
	class BatchRenderer2D : Renderer2D
	{
	public:
		BatchRenderer2D(const int MAX_SHAPES, unsigned int VERTEX_SIZE);

		void Push(const Renderable2D* shape) override;
		void Flush() override;
	private:
		VertexArray VAO;
		VertexBuffer VBO;
		IndexBuffer* IBO;
		const int& MAX_SHAPES;
		const int& SHAPE_SIZE = VERTEX_SIZE * SPRITE_VERTICES;
		const int VERTEX_SIZE;
		const int BUFFER_SIZE = SHAPE_SIZE* VERTEX_SIZE;
		const int IBO_SIZE = VERTEX_SIZE * 6;
		static constexpr int SPRITE_VERTICES{ 4 };

	};
}