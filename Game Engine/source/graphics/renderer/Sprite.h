#pragma once
#include "maths/Vector.h"
#include "graphics/gl_types/Buffers.h"
#include "graphics/renderer/simple_shapes/Square.h"
#include "Material.h"


class Sprite
{
public:
	Sprite(const maths::vec3f& pos, float width, float height, graphics::Material mat)
		:pos(pos),
		width(width),
		height(height),
		m(mat)
	{
		GLfloat vertices[] =
		{
			0,     0,      0,
			0,     height, 0,
			width, height, 0,
			width, 0,      0
		};

		GLfloat colour[] =
		{
			m.colour.x, m.colour.y, m.colour.z, m.colour.w,
			m.colour.x, m.colour.y, m.colour.z, m.colour.w,
			m.colour.x, m.colour.y, m.colour.z, m.colour.w,
			m.colour.x, m.colour.y, m.colour.z, m.colour.w
		};

		graphics::VertexBuffer vPos = graphics::VertexBuffer(vertices, sizeof(vertices));
		vPos.PushLayout(3, GL_FLOAT);
		VAO.Set(vPos, 0);

		graphics::VertexBuffer vColour = graphics::VertexBuffer(vertices, sizeof(vertices));
		vColour.PushLayout(4, GL_FLOAT);
		VAO.Set(vColour, 1);
	}
	inline unsigned int GetID() const { return VAO.GetId(); };
	inline graphics::Material GetMaterial() const { return m; };

private:
	maths::vec3f pos;
	float width, height;
	graphics::VertexArray VAO;
	graphics::Material m;
};