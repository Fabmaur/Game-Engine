
#pragma once

#include "graphics/renderer/Layer.h"
#include <map>


/*Demo menu is a layer which renders an ImGui interface onto 
the screen. The interface consists of buttons which when 
pressed activates a corresponding layer and runs it.*/
class DemoMenu : public graphics::Layer
{
public:
	virtual void onEvent(EventMessage& event) override;
	virtual void Init() override;
	virtual void RunMain() override;
	void CreateDemo(const std::string& name, Layer* demo);
	virtual ~DemoMenu() override;

private:
	// Holds a map of layers with a corresponding string as the key
	std::map<std::string, graphics::Layer*> demoes;
	// Holds a key of the currently active demo
	std::string currentDemo;
};
