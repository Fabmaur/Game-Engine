#include "core/Engine.h"


int main()
{
	core::Engine engine("Awesome Game Engine!", 1920, 1080);
	engine.Start();
	engine.Stop();
}