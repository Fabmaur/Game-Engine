#pragma once
#include "Renderable2D.h"
#include "maths/Matrix4.h"
#include <vector>
#include "Text.h"

namespace graphics
{
	/*Base renderer class which specifies functions that
	should be implemented by the derived renderer classes.*/
	class Renderer2D
	{
	public:
		Renderer2D()
		{
			transMat.push_back(maths::mat4f(1));
		}

		void PushMat(maths::mat4f mat, bool ignore = false)
		{
			if (ignore)
				transMat.push_back(mat);
			else
				transMat.push_back(mat * (transMat.back()));
		}

		void PopMat()
		{
			if (transMat.size() > 1)
				transMat.pop_back();
		}

		virtual void Push(const Renderable2D* sprite) = 0;
		virtual void RenderText(Text& text, maths::vec2f pos, maths::vec4f colour) {}
		virtual void RenderAndPop() = 0;
		virtual ~Renderer2D() {};
	protected:
		std::vector<maths::mat4f> transMat;

	};
}