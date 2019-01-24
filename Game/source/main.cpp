#include "debug/ProjectLog.h"
#include "core/Engine.h"


int main()
{
	static debug::ProjectLog log;
	GAME_STATUS("Loading Game...");
	core::Engine engine("Hyperion Engine", 1920, 1080);
	engine.Start();
	engine.Stop();
}