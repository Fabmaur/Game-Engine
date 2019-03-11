#pragma once

#include "graphics/renderer/Layer.h"
#include <map>

class DemoMenu : public graphics::Layer
{
public:
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	void CreateDemo(const std::string& name, Layer* demo);
	virtual ~DemoMenu() override;

private:
	std::map<std::string, graphics::Layer*> demoes;
	std::string currentDemo;
};
