#pragma once

#include "graphics/renderer/Layer.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Mesh.h"
#include "graphics/renderer/Texture.h"
#include "graphics/renderer/Renderable2D.h"
#include "graphics/renderer/SpriteRenderer.h"

class Demo2 : public graphics::Layer
{
	/* Demo to show the sprite renderer rendering a single
	-sprite. */
public:
	Demo2() = default;
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~Demo2();
private:
	graphics::Shader shader;
	graphics::Texture* tex;
	graphics::Renderable2D* sprite;
	graphics::SpriteRenderer renderer;
	maths::mat4f proj;
};