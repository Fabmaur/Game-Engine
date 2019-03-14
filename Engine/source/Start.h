#pragma once
#include "debug/GLDebug.h"
#include "core/Engine.h"

/* Engine start file to be included in the games cpp file. */
int main()
{
	// Creates log and starts the engine
	static debug::ProjectLog log;
	GAME_STATUS("Loading Game...");
	core::Engine engine("Hyperion Engine", 1920, 1080);
	engine.Start();
	engine.Stop();
}