#include "Fluid_Sim.h"
#include "Tools.h"
#include "UI.h"

#define gridX 10
#define halfGridX (griX/2)
#define gridY 10
#define halfGridY (gridY/2)
#define gridSize (gridX * gridY)
#define numberOfParticles 10

//Constants
const Button settingsButton = { { 10,10 }, { 20,20 } };
const float frameRateCap = 1000 / 60;
const float physicsFrameRateCap = 1000 / 60;
//

//Globals
Vector2 screenSize = { 700, 700 };
Vector2 screenMidle;
int deltaTime;
Particle particles[numberOfParticles];
Vector2 grid[gridSize];
int lastTick = 0;
extern Vector2 mousePos;
//

int SDL_main(int argc, char *argv[])
{
	Initialization();

	//Setup Started
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL failed to initialise: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenSize.x, screenSize.y, 0);

	if (!window)
	{
		printf("Failed to create window\n");
		printf("SDL2 Error: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//Setup Finished


	bool keep_window_open = true;
	int fps = 0;
	float oldTime = 0;
	float newTime = 0;
	while (keep_window_open)
	{
		newTime = SDL_GetTicks();
		if (newTime - oldTime >= frameRateCap)
		{
			EventsHandler(&keep_window_open);
			FrameUpdate();
			Render_Everything(renderer);

			deltaTime = newTime - oldTime;
			if (deltaTime) fps = 1000 / deltaTime;
			char* windowText = "";
			sprintf(windowText, "Window - %d", fps);
			SDL_SetWindowTitle(window, windowText);
			oldTime = newTime;
		}
	}



	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}

void Initialization()
{
	screenMidle = DivideVectorByValue(screenSize, 2);
	GetCosAndSinValues();
	SeedRandom();
	SpawnParticles();
}

void EventsHandler(bool *keep_window_open)
{
	SDL_Event e;
	while (SDL_PollEvent(&e) > 0)
	{
		switch (e.type)
		{
		case SDL_QUIT:
			*keep_window_open = false;
			break;
		case SDL_MOUSEBUTTONDOWN:

			MouseButtonPress(e.button);
			break;
		}
	}
}

void FrameUpdate()
{
	GetMousePos();
	if (SDL_GetTicks() - lastTick >= physicsFrameRateCap)
	{
		lastTick = SDL_GetTicks();
		ParticleInteractions();
	}
}


void Render_Everything(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	//////

	Draw_Circle(renderer, mousePos, 50, WHITE);

	/////
	SDL_RenderPresent(renderer);
}


void MouseButtonPress(SDL_MouseButtonEvent button)
{
	if (button.button == SDL_BUTTON_LEFT)
	{
		//do whatever
	}
}

void SpawnParticles()
{
	for (int i = 0; i < gridSize; i++)
	{
		
	}
}

void ParticleInteractions()
{

}
