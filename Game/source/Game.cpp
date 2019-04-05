#include "Game.h"
#include "Demo1/Demo1.h"
#include "Demo2/Demo2.h"
#include "Demo3/Demo3.h"
#include "Demo4/Demo4.h"
#include "Demo5/Demo5.h"
#include "Demo6/Demo6.h"
#include "Demo7/Demo7.h"
#include "Demo8/Demo8.h"
#include "DemoMenu.h"
#include "Start.h"

Game::Game()
{
	//Creating layers to the layer list
	Demo1* dragonModel = new Demo1;
	Demo2* singleSprite = new Demo2;
	Demo3* BatchRendererOneSprite = new Demo3;
	Demo4* BatchRendererMultipleSprite = new Demo4;
	Demo5* text = new Demo5;
	Demo6* cube = new Demo6;
	Demo7* events = new Demo7;
	//Demo8* dragonWithCamera = new Demo8;

	DemoMenu* menuLayer = new DemoMenu;
	menuLayer->CreateDemo("Dragon Model", dragonModel);
	menuLayer->CreateDemo("Single Sprite Renderer", singleSprite);
	menuLayer->CreateDemo("Batch renderer one texture", BatchRendererOneSprite);
	menuLayer->CreateDemo("Batch renderer with multiple textures", BatchRendererMultipleSprite);
	menuLayer->CreateDemo("Text rendering", text);
	menuLayer->CreateDemo("Creating a model from raw vertices and indices", cube);
	menuLayer->CreateDemo("Events", events);
	//menuLayer->CreateDemo("Dragon with camera", dragonWithCamera);

	layers.push_back(dragonModel);
	layers.push_back(singleSprite);
	layers.push_back(BatchRendererOneSprite);
	layers.push_back(BatchRendererMultipleSprite);
	layers.push_back(text);
	layers.push_back(cube);
	layers.push_back(events);
	//.push_back(dragonWithCamera);
	layers.push_back(menuLayer);
}

Game* CreateApp()
{
	/*Returns an instance of the game which the engine
	then uses to initialize itself*/
	return new Game;
}