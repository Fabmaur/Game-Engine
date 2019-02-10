#include "Game.h"
#include "GameLayer.h"

Game::Game()
{
	GameLayer* gameLayer = new GameLayer;
	layers.push_back(gameLayer);
}

