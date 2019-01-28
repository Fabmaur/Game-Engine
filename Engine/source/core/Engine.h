#pragma 
#include "graphics/renderer/window.h"

namespace core
{
	/*Controls the game engine*/

	class Engine 
	{
	public:
		Engine(const int width = 800, const int height = 600); // Creates window
		Engine(const char* title, const int width = 800, const int height = 600); // Creates window
		void Start();
		void Stop();

	private:
		graphics::Window window;
		
	};
}