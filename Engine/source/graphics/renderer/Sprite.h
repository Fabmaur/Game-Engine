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
		Sprite(Shader& shader, Texture& tex, maths::vec3f pos, maths::vec2f size)
			:shader(shader),
			tex(tex),
			pos(pos),
			size(size)
		{
			const float vertices[]
			{
				//Position							    //tex coords
				pos.x, pos.y - size.y, pos.z, 		    0.0f, 0.0f,			//bottom left
				pos.x, pos.y, pos.z,					0.0f, 1.0f,			//top left
				pos.x + size.x, pos.y , pos.z,		    1.0f, 1.0f,			//top right
				pos.x + size.x, pos.y - size.y, pos.z,  1.0f, 0.0f 			//bottom right
			};


			VertexBuffer VBO(vertices, sizeof(vertices));
			VBO.PushLayout(3, GL_FLOAT);
			VBO.PushLayout(2, GL_FLOAT);

			const float indices[]
			{
				0, 1, 2, // triangle top left
				0, 2, 3  // triangle bottom right
			};

			IndexBuffer IBO(indices, sizeof(indices)/sizeof(float));
			VertexArray v;
			v.SetInOne(VBO);
			v.BindIBO(IBO);
			VAO = v;

		}
		inline VertexArray& GetVAO() { return VAO; };
		inline Shader& GetShader() { return shader; };
		inline Texture& GetTexture() { return tex; };
		inline maths::vec3f& GetPos() { return pos; };
	private:
		maths::vec3f& pos;
		maths::vec2f& size;

		VertexArray VAO;
		Shader& shader;
		Texture& tex;

	};
}