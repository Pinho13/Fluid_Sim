// Fluid_Sim.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include "Tools.h"
#include <SDL_main.h>
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h> 

typedef struct {
	Vector2 pos, vel;
	int radius;
}particles;

typedef struct {
	Vector2 pos;
	int radius;
}UIButtons;

void Initialization();
void FrameUpdate();
void Render_Everything(SDL_Renderer* renderer);



// TODO: Reference additional headers your program requires here.

