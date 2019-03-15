#include "Game.h"
#include "Demo1/Demo1.h"
#include "DemoMenu.h"
#include "Start.h"

Game::Game()
{
	//Pushing layers to the layer list
	Demo1* testLayer = new Demo1;

	DemoMenu* menuLayer = new DemoMenu;
	menuLayer->CreateDemo("Test Layer", testLayer);
	   
	layers.push_back(testLayer);
	layers.push_back(menuLayer);
}

Game* CreateApp()
{
	/*Returns an instance of the game which the engine
	then uses to initialize itself*/
	return new Game;
}