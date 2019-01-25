#pragma once
#include "graphics/gl_types/VertexArray.h"
#include "graphics/gl_types/IndexBuffer.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Texture.h"
#include "maths/Vector.h"


namespace graphics
{

	class Sprite
	{
	public:
		Sprite() = delete;
		Sprite(VertexArray VAO, Shader shader, Texture tex, maths::vec2f pos)
			:VAO(VAO),
			shader(shader),
			tex(tex),
			pos(pos)
		{}
		inline VertexArray& GetVAO() { return VAO; };
		inline Shader& GetShader() { return shader; };
		inline Texture& GetTexture() { return tex; };
		inline maths::vec2f& GetPos() { return pos; };
	private:
		maths::vec2f pos;
		maths::vec2f size;

		VertexArray VAO;
		Shader shader;
		Texture tex;

	};
}