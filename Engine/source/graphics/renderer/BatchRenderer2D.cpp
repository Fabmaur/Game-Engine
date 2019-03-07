#include "pch.h"
#include "BatchRenderer2D.h"
#include "Font.h"


namespace graphics
{

	BatchRenderer2D::BatchRenderer2D(Shader* shader, const int MAX_SHAPES)
		:MAX_SHAPES(MAX_SHAPES),
		shader(shader),
		VERTEX_SIZE(sizeof(graphics::Vertex)),
		SHAPE_SIZE(4 * sizeof(graphics::Vertex)),
		BUFFER_SIZE(SHAPE_SIZE * MAX_SHAPES),
		IBO_COUNT(MAX_SHAPES * 6)
	{

		fontShader = new Shader("../Game/resources/Font.shader");
		int texUnitID[] = {
			0, 1, 2, 3, 4, 5, 6, 7, 8,
			9, 10, 11, 12, 13, 14, 15
		};
		shader->Bind();
		shader->SetUniformiv("textures", 16, texUnitID);
		shader->Unbind();

		VAO.Bind();
		VBO = VertexBuffer(BUFFER_SIZE);
		VBO.PushLayout(3, GL_FLOAT); // Vertex position
		VBO.PushLayout(2, GL_FLOAT); // Texture coordinates
		VBO.PushLayout(1, GL_FLOAT); // Texture unit
		VBO.PushLayout(4, GL_FLOAT); // Setting colour
		VAO.SetVertexAttribArray(VBO);

		unsigned int* indices = new unsigned int[IBO_COUNT];

		int offset = 0;
		for (int i = 0; i < IBO_COUNT; i += 6) // For every rect make index buffer
		{
			indices[i] = offset;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;
			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset;
			offset += 4;
		}

		IndexBuffer IBO(indices, IBO_COUNT);

		VAO.BindIBO(IBO);
		VBO.Bind();
		offset = 0;
	}

	void BatchRenderer2D::Push(const Renderable2D* renderable)
	{
		BatchSprite* rect = (BatchSprite*)renderable;
		
		maths::vec3f pos = rect->GetPos();
		pos = transMat.back().MultiplyByVec3f(pos);
		const float sizeX = rect->GetSize().x;
		const float sizeY = rect->GetSize().y;
		
		maths::vec2f texPos = rect->GetTexPos();
		const float texSizeX = rect->GetTexSize().x;
		const float texSizeY = rect->GetTexSize().y;
			   
		const float r = rect->GetColour().r;
		const float g = rect->GetColour().g;
		const float b = rect->GetColour().b;
		const float a = rect->GetColour().a;
		const unsigned int texUnit = rect->GetTexture() == nullptr ? 0 : rect->GetTexture()->GetTUID();
		
		bool found = false;
		for (int i = 0; i < usedTexUnits.size(); i++)
			if (usedTexUnits[i] == texUnit)
				found = true;

		if (!found)
			usedTexUnits.push_back(texUnit);

		const float vertices[]
		{
			//position				  			   Texture Coords								TexUnit		Colour
			pos.x,		   pos.y - sizeY, pos.z,	texPos.x,			 texPos.y,				texUnit,	r, g, b, a,		//bottom left
			pos.x,		   pos.y,		  pos.z,	texPos.x,		     texPos.y + texSizeY,	texUnit,	r, g, b, a,		//top left
			pos.x + sizeX, pos.y,		  pos.z,	texPos.x + texSizeX, texPos.y + texSizeY,	texUnit,	r, g, b, a,		//top right
			pos.x + sizeX, pos.y - sizeY, pos.z,	texPos.x + texSizeX, texPos.y,				texUnit,	r, g, b, a		//bottom right
		};
		GLCheck(glBufferSubData(GL_ARRAY_BUFFER, offset, sizeof(vertices), vertices));
		offset += sizeof(vertices);
	}

	void BatchRenderer2D::RenderAndPop()
	{

		shader->Bind();
		for (int i = 0; i < usedTexUnits.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i + 1);
			glBindTexture(GL_TEXTURE_2D, usedTexUnits[i]);
		}

		VAO.Bind();
		glDrawElements(GL_TRIANGLES, IBO_COUNT, GL_UNSIGNED_INT, 0);

		offset = 0;
	}

	void BatchRenderer2D::RenderText(Text& text, maths::vec2f pos, maths::vec4f colour)
	{
		maths::mat4f mvp = maths::Ortho(0.0f, 1980.0f, 0.0f, 1080.0f, -1.0f, 1.0f);
		fontShader->Bind();
		fontShader->SetUniformMat4f("mvp", mvp);
		fontShader->SetUniform3f("textColor", colour.r, colour.g, colour.b);
		glActiveTexture(GL_TEXTURE0);
		VertexArray aVAO;
		aVAO.Bind();
		VertexBuffer aVBO(sizeof(float) * 6 * 4);
		aVBO.PushLayout(4, GL_FLOAT);
		aVAO.SetVertexAttribArray(aVBO);

		for (int i = 0; i < text.GetTextStr().length(); i++)
		{
			aVAO.Bind();
			aVBO.Bind();
			Glyph glyph = text.GetFont().GetGlyph(text.GetTextStr()[i]);

			
			float x = pos.x + glyph.bearing.x;
			float y = pos.y - (glyph.size.y - glyph.bearing.y);

			float w = glyph.size.x;
			float h = glyph.size.y;
			// Update VBO for each character
			float vertices[] =	
			{
				 x,     y + h,   0.0, 1.0,
				 x,     y,       0.0, 0.0,
				 x + w, y,       1.0, 0.0,

				 x,     y + h,   0.0, 1.0,
				 x + w, y,       1.0, 0.0,
				 x + w, y + h,   1.0, 1.0
			};
			glBindTexture(GL_TEXTURE_2D, glyph.TUID);
			// Update VBO buffer
			
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); 

			
			// Render quad
			glDrawArrays(GL_TRIANGLES, 0, 6);
			// Add advance to position
			pos.x += (glyph.advance >> 6); // Bitshift to get amount in pixels
		}
		aVBO.Delete();
		aVAO.Delete();
		glBindTexture(GL_TEXTURE_2D, 0);
		fontShader->Unbind();
	}

	void BatchRenderer2D::SetShader(Shader* aShader)
	{
		shader = aShader;
	}
} 