#pragma 
#include "graphics/renderer/window.h"
#include "UserApplication.h"
#include "../../Game/Source/Game.h"

extern Game* CreateApp();

namespace core
{
	/*Controls the game engine*/
	
	class Engine 
	{
	public:
		Engine(const char* title = "Hello World", const int width = 800, const int height = 600); // Creates window
		void Start();
		void Stop();

	private:
		graphics::Window window;
		UserApplication* app;

	};
}