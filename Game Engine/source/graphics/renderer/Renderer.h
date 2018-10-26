#pragma once

#include "graphics/renderer/simple_shapes/Shapes.h"
#include "graphics/renderer/Shader.h"
#include "graphics/gl_types/Buffers.h"
#include <queue>

namespace graphics
{
	using namespace graphics;
	class Renderer
	{
	public:
		void DrawRectangle();
		void DrawCube();
		void CreateShape(unsigned int shapeID);
		void SetShader(const char* string);

		void DrawTriangle();
		void DrawSquare();
		void Draw();
	private:
		std::vector<unsigned int> renderObjects;
	
	};
}
