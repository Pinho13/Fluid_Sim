// Fluid_Sim.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#ifndef FLUID_SIM_H
#define FLUID_SIM_H
#include "Tools.h"
#include "UI.h"
#include <SDL_main.h>
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h> 


typedef struct Particle{
	Vector2 pos, vel;
	int radius;
}Particle;

//Functions
void Initialization();
void EventsHandler(bool* keep_window_open);
void FrameUpdate();
void Render_Everything(SDL_Renderer* renderer);
void MouseButtonPress(SDL_MouseButtonEvent button);
void SpawnParticles();
void ParticleInteractions();
//EndFunctions



// TODO: Reference additional headers your program requires here.
#endif
