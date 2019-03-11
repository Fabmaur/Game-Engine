#pragma once

#include "graphics/renderer/Shader.h"
#include "graphics/renderer/BatchRenderer2D.h"
#include "events/Events.h"
#include "graphics/renderer/Layer.h"
#include "graphics/renderer/Sprite.h"
#include "graphics/renderer/SpriteRenderer.h"
#include "graphics/renderer/Text.h"
#include "misc/Timer.h"

class Demo1 : public graphics::Layer
{
public:
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~Demo1();
private:
	graphics::Renderer2D* renderer;
	graphics::Renderable2D* renderable[2];
	graphics::Shader* shader;
	graphics::Texture* texture;
	graphics::Texture* texture2;
	graphics::Text text;
	misc::Timer timer;
	maths::mat4f proj;


};