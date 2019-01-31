#pragma once

#include "graphics/renderer/Renderable2D.h"
#include "graphics/gl_types/Buffers.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Texture.h"
#include "maths/Vector.h"


namespace graphics
{
	/*Creates sprites which can be pushed into a sprite renderer
	and rendered.*/

	class Sprite : public Renderable2D
	{
	public:
		Sprite() = delete;
		~Sprite()
		{
			HP_ERROR("Desroying Sprite.");
		}
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

			const unsigned int indices[]
			{
				0, 1, 2, // triangle top left
				0, 2, 3  // triangle bottom right
			};

			IndexBuffer IBO(indices, sizeof(indices)/sizeof(float));
			VAO.SetVertexAttribArray(VBO);
			VAO.BindIBO(IBO);
		}
		inline const VertexArray& GetVAO() const { return VAO; };
		inline Shader& GetShader() const { return shader; };
		inline Texture& GetTexture() const { return tex; };
		inline maths::vec3f& GetPos() const { return pos; };
	private:
		maths::vec3f& pos;
		maths::vec2f& size;

		VertexArray VAO;
		Shader& shader;
		Texture& tex;

	};
}