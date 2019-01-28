#pragma once

#include "graphics/gl_types/Buffers.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Texture.h"
#include "maths/Vector.h"


namespace graphics
{

	class Sprite
	{
	public:
		Sprite() = delete;
		Sprite(Shader shader, Texture tex, maths::vec3f pos, maths::vec3f size)
			:shader(shader),
			tex(tex)
		{
			const float vertices[]
			{
				//Position							   //tex coords
				pos.x, pos.y - size.y, 0.0f, 		   0.0f, 0.0f,			//bottom left
				pos.x, pos.y, 0.0f,					   0.0f, 1.0f,			//top left
				pos.x + size.x, pos.y , 0.0f,		   1.0f, 1.0f,			//top right
				pos.x + size.x, pos.y - size.y, 0.0f,  1.0f, 0.0f 			//bottom right
			};


			VertexBuffer VBO(vertices, sizeof(vertices));
			VBO.PushLayout(3, GL_FLOAT);
			VBO.PushLayout(2, GL_FLOAT);

			const 

		
		
		}
		inline VertexArray& GetVAO() { return VAO; };
		inline Shader& GetShader() { return shader; };
		inline Texture& GetTexture() { return tex; };
		inline maths::vec3f& GetPos() { return pos; };
	private:
		maths::vec3f pos;
		maths::vec2f size;

		VertexArray VAO;
		Shader shader;
		Texture tex;

	};
}