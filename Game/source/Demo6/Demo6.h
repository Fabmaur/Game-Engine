#pragma once

#include "graphics/renderer/Layer.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Mesh.h"
#include "graphics/renderer/Texture.h"

class Demo6 : public graphics::Layer
{
	/* Demo to show rendering from mesh class from 
	raw vertex and index data. */
public:
	Demo6() = default;
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~Demo6();
private:
	graphics::Shader shader;
	graphics::Texture* tex;
	graphics::Mesh block;
	maths::mat4f proj;
};