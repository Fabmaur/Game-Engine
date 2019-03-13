#pragma 
#include "graphics/renderer/window.h"
#include "UserApplication.h"
#include "../../Game/Source/Game.h"

// Looks for the external function CreateApp and defines it it's found
extern Game* CreateApp();

namespace core
{
	/* The Engine class takes an instance of the game and then
	processes it. It is also responsible for creating a
	window and managing it. */
	
	class Engine 
	{
	public:
		Engine(const char* title = "Hyperion Engine", const int width = 800,
			const int height = 600); 
		void Start();
		void Stop();

	private:
		graphics::Window window;
		UserApplication* app; // Stores an instance of the game

	};
}