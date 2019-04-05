#pragma once

#include "graphics/renderer/Layer.h"
#include "graphics/renderer/Shader.h"
#include "graphics/renderer/Mesh.h"
#include "graphics/renderer/Texture.h"
#include "graphics/renderer/CameraFPS.h"

class Demo8 : public graphics::Layer
{
public:
	Demo8() = default;
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	~Demo8();
private:
	graphics::Shader shader;
	graphics::Texture* tex;
	graphics::Mesh dragon;
	maths::mat4f proj;
	graphics::CameraFPS camera;
};