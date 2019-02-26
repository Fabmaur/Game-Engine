#pragma once
#include "Renderer2D.h"
#include "Shader.h"
#include "graphics/renderer/Renderable2D.h"
#include "graphics/gl_types/Buffers.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Texture.h"
#include "maths/Vector.h"
#include "graphics/renderer/SpriteGroup.h"
#include <map>

namespace graphics
{
	/*Batch renderer which can be used to render 2D sprites and shapes*/
	//Will only work with shapes at the start
	class BatchRenderer2D : public Renderer2D
	{
	public:
		BatchRenderer2D(Shader* shader, const int MAX_SHAPES);
		void Push(const Renderable2D* shape) override;
		void RenderAndPop() override;
		void SetShader(Shader* aShader);
	private:
		Shader* shader;
		VertexArray VAO;
		VertexBuffer VBO;
		std::vector<unsigned int> usedTexUnits;
		
		const int MAX_SHAPES;
		const int VERTEX_SIZE;
		const int SHAPE_SIZE;
		const int BUFFER_SIZE;
		const int IBO_COUNT;
		int offset;
	};
}