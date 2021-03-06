#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "Game.h"

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));

	//game initalisation
	Game* game = new Game();

	//Splash screen
	application->SetColor(Color(0, 0, 0, 255));
	application->DrawText("Hello World", 800 / 2, 600 / 2);

	// For the background
	//application->SetColor(Color(255, 255, 255, 255));
	application->SetColor(Color(255, 62, 150, 255));


	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){

				case SDLK_SPACE:
					game->moveHero();

				default:
					break;
				}
			}
		}
		
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}