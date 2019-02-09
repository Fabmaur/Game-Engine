#pragma once

#include <vector>
#include "graphics/renderer/Layer.h"

namespace graphics
{
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();
		void Push(Layer* layer);
		void PushOverlay(Layer* layer);
		void Pop();
		void PopOverlay();
		void Render();
		void Update();
	private:
		std::vector<Layer*> layers;
	};
}