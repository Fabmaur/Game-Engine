 #pragma once

#include "graphics/renderer/Renderable2D.h"
#include "graphics/gl_types/Buffers.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Texture.h"
#include "maths/Vector.h"


namespace graphics
{
	/*Creates single sprites which are sprites which hold their own vertex arrays and shaders.*/

	static maths::vec4f defaultColour{ 1.0f, 0.0f, 0.0f, 1.0f };
	class SingleSprite : public Renderable2D
	{
	public:
		SingleSprite() = delete;

		// For texture
		SingleSprite(Shader& shader, Texture& tex, maths::vec3f pos, maths::vec2f size)
			:Renderable2D(pos, size, defaultColour),
			shader(shader),
			tex(&tex)

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

			CreateAndBindIBO(VBO);

		}
		
		
		//For colour
		SingleSprite(Shader& shader, maths::vec3f pos, maths::vec2f size, maths::vec4f colour)
			:Renderable2D(pos, size, colour),
			shader(shader),
			tex(nullptr)
		
		{
			const float vertices[]
			{
				//Position							    //colour 
				pos.x, pos.y - size.y, pos.z, 			colour.r, colour.g, colour.b, colour.a,		//bottom left
				pos.x, pos.y, pos.z,					colour.r, colour.g, colour.b, colour.a,		//top left
				pos.x + size.x, pos.y , pos.z,		    colour.r, colour.g, colour.b, colour.a,		//top right
				pos.x + size.x, pos.y - size.y, pos.z,  colour.r, colour.g, colour.b, colour.a 		//bottom right
			};
			VertexBuffer VBO(vertices, sizeof(vertices));
			VBO.PushLayout(3, GL_FLOAT);
			VBO.PushLayout(4, GL_FLOAT);
			CreateAndBindIBO(VBO);
		}



		inline const VertexArray& GetVAO() const { return VAO; };
		inline Shader& GetShader() const { return shader; };
		inline Texture GetTexture() const { return tex == nullptr ?  Texture() : *tex ; };

	private:
		void CreateAndBindIBO(VertexBuffer& VBO)
		{
			const unsigned int indices[]
			{
				0, 1, 2, // triangle top left
				0, 2, 3  // triangle bottom right
			};

			IndexBuffer IBO(indices, sizeof(indices) / sizeof(float));
			VAO.SetVertexAttribArray(VBO);
			VAO.BindIBO(IBO);
		}

	private:
		VertexArray VAO;
		Shader& shader;
		Texture* tex;

	};

	/*Batch sprites are containers which hold vertex information for the sprite
	. This data is then passed on to a batch renderer where the data is transferred 
	into one vertex buffer where it can be rendered in one call.*/

	class BatchSprite : public Renderable2D
	{
		//For Colour
	public:
		BatchSprite(maths::vec3f pos, maths::vec2f size, maths::vec4f colour)
			:Renderable2D(pos, size, colour),
			tex(nullptr)
		{}

		BatchSprite(maths::vec3f pos, maths::vec2f size, std::string texturePath)
			:Renderable2D(pos, size, defaultColour),
			tex(new Texture(texturePath))
		{}


		BatchSprite(maths::vec3f pos, maths::vec2f size, Texture* tex )
			:Renderable2D(pos, size, defaultColour),
			tex(tex)
		{}

		~BatchSprite()
		{
			delete tex;
		}

		inline Texture* GetTexture() const { return tex; };

	private:
		Texture* tex;
	};
}