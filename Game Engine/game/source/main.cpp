#include "core/Engine.h"

int main()
{
	core::Engine engine("Awesome Game Engine!", 1000, 1000);
	engine.Start();
	engine.Stop();
}