#pragma once

#include "graphics/renderer/Shader.h"
#include "graphics/simple_shapes/Shape.h"
#include "graphics/renderer/BatchRenderer2D.h"
#include "events/Events.h"
#include "graphics/renderer/Layer.h"

class GameLayer : public graphics::Layer
{
public:
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~GameLayer();
private:
	graphics::Renderer2D* renderer;
	graphics::Rect* renderable;
	graphics::Shader* shader;

};