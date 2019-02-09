#pragma once
#include "core/UserApplication.h"
#include "graphics/renderer/Renderer2D.h"
#include "graphics/renderer/Renderable2D.h"
#include "graphics/renderer/Shader.h"
#include "graphics/simple_shapes/Shape.h"
#include "events/Events.h"

class Game : public core::UserApplication
{
public:
	virtual void EventCallBack(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~Game();
private:
	graphics::Renderer2D* renderer;
	graphics::Rect* renderable;
	graphics::Shader* shader;
};