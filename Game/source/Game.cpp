#include "Game.h"
#include "Demo1/Demo1.h"
#include "DemoMenu.h"
#include "Start.h"

Game::Game()
{
	Demo1* gameLayer = new Demo1;
	DemoMenu* menuLayer = new DemoMenu;
	menuLayer->CreateDemo("rand", gameLayer);
	layers.push_back(gameLayer);
	layers.push_back(menuLayer);
}

Game* CreateApp()
{
	return new Game;
}