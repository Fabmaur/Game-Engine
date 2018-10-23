#pragma once

#include "graphics/renderer/simple_shapes/Cube.h"
#include "graphics/renderer/Shader.h"


namespace graphics
{
	using namespace graphics;
	class Renderer
	{
	public:
		Renderer();
		void CreateLine();
		void CreateTriangle();
		void CreateRectangle();
		void CreateCube(graphics::CubePlain c, Shader s);
		void DrawSquare();
		void DrawTriangle();
		void DrawRectangle();
		void DrawCube();
	private:

	};
}