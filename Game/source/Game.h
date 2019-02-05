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
	bool EventCallBack(EventMessage& event) override;
	void Init();
	void RunMain();
	~Game();
private:
	graphics::Renderer2D* renderer;
	graphics::Rect* renderable;
	graphics::Shader* shader;
};