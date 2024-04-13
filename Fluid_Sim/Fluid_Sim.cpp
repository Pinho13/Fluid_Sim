
#include <SDL_main.h>
#include <SDL.h>
#include "Fluid_Sim.h"

using namespace std;

int SDL_main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	cout << "Hello CMake." << endl;

	SDL_Quit();
	return 0;
}
