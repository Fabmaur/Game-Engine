#pragma once

#include "graphics/renderer/Layer.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Mesh.h"
#include "graphics/renderer/Texture.h"
#include "graphics/renderer/CameraFPS.h"
#include "graphics/renderer/Renderer2D.h"
#include "graphics/renderer/Text.h"

class Demo5 : public graphics::Layer
{
	/* Demo to show text rendering*/
public:
	Demo5() = default;
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~Demo5();
private:
	graphics::Renderer2D* renderer;
	graphics::Text text;
};