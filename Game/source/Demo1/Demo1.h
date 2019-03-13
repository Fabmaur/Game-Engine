#pragma once

#include "graphics/renderer/Layer.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Mesh.h"

class Demo1 : public graphics::Layer
{
public:
	Demo1() = default;
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~Demo1();
private:
	graphics::Shader shader;
	graphics::Mesh cube;
	maths::mat4f proj;


};