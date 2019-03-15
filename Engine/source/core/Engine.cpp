#include "pch.h"
#include "Engine.h"

namespace core
{
	Engine::Engine(const char* title, const int width, const int height)
		:window(graphics::Window(title, width, height))
	{
		/* Assigns UserApplication* app to the returned game instance
		from the external CreateApp() function */
		app = CreateApp(); 
		
		HP_STATUS("Initializing Engine");
		// Sets default colour for window
		window.SetColour(1.0f, 1.0f, 1.0f, 1.0f); 
	}

	void Engine::Start()
	{
		// Sends an event call back defined in the app to the window
		window.SetEventCallBack(app->GetEventCallBack());
		// Initializes the application/game
		app->Init();
	
		// Game Loop
		while (!window.IsWindowClosed())
		{
			// Runs the game loop code for the application
			app->RunMain();
			window.Update();
		}
	}

	void Engine::Stop()
	{
		window.Terminate();
	}
}