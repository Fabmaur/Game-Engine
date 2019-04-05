#pragma once

#include "graphics/renderer/Layer.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Mesh.h"
#include "graphics/renderer/Texture.h"
#include "graphics/renderer/Renderable2D.h"
#include "graphics/renderer/Renderer2D.h"


class Demo4 : public graphics::Layer
{
	/* Demo to show batch renderer rendering multiple
	sprites of different textures. */
public:
	Demo4() = default;
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~Demo4();
private:
	graphics::Shader shader;
	graphics::Texture* tex;
	graphics::Renderable2D* sprite[4];
	graphics::Renderer2D* renderer;
	maths::mat4f proj;
};