
#include <SDL_main.h>
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h> 
#include "Fluid_Sim.h"



int SDL_main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL failed to initialise: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);

	if (!window)
	{
		printf("Failed to create window\n");
		printf("SDL2 Error: %s\n", SDL_GetError);
		return -1;
	}

	SDL_Surface* window_surface = SDL_GetWindowSurface(window);

	if (!window_surface)
	{
		printf("Failed to get the surface from the window\n");
		printf("SDL2 Error: %s\n", SDL_GetError);
		return -1;
	}

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
			SDL_UpdateWindowSurface(window);
		}
	}
	return 0;
}
