#include "Fluid_Sim.h"
#include "Tools.h"
#include "UI.h"


//Constants
const UIButtons toolsButton = { { 10, 10 }, 5 };
//



int SDL_main(int argc, char *argv[])
{
	//Setup Started
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL failed to initialise: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, 0);

	if (!window)
	{
		printf("Failed to create window\n");
		printf("SDL2 Error: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Initialization();
	//Setup Finished



	bool keep_window_open = true;
	while (keep_window_open)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) > 0)
		{
			switch (e.type)
			{
				case SDL_QUIT:
					keep_window_open = false;
					break;
			}
		}
		FrameUpdate();
		Render_Everything(renderer);
	}



	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}

void Initialization()
{
	GetCosAndSinValues();
}


void FrameUpdate()
{
	
}


void Render_Everything(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	//////

	//Draw_Rect(renderer, (Vector2) { 75, 75 }, (Vector2) { 550, 550 }, WHITE);
	//Draw_Circle(renderer, GetMousePos(), 100, WHITE);

	/////
	SDL_RenderPresent(renderer);
}