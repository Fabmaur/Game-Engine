#pragma once

#include "graphics/renderer/Shader.h"
#include "graphics/renderer/BatchRenderer2D.h"
#include "events/Events.h"
#include "graphics/renderer/Layer.h"
#include "graphics/renderer/Sprite.h"
#include "graphics/renderer/SpriteRenderer.h"

class GameLayer : public graphics::Layer
{
public:
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~GameLayer();
private:
	graphics::Renderer2D* renderer;
	graphics::Renderable2D* renderable;
	graphics::Shader* shader;
	graphics::Texture* texture;

};