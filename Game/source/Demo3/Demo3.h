#pragma once
#include "graphics/renderer/Layer.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Mesh.h"
#include "graphics/renderer/Texture.h"
#include "graphics/renderer/Renderable2D.h"
#include "graphics/renderer/BatchRenderer2D.h"

class Demo3 : public graphics::Layer
{
	/* Demo to show batch renderer rendering one 
		textured sprite. */
public:
	Demo3() = default;
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~Demo3();
private:
	graphics::Shader shader;
	graphics::Texture* tex;
	graphics::Renderable2D* sprite;
	graphics::Renderer2D* renderer;
	maths::mat4f proj;
};