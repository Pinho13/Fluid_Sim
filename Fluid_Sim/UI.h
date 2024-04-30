#pragma once
#ifndef UI_H
#define UI_H
#include <SDL_main.h>
#include <SDL.h>
#include "Fluid_Sim.h"
#include <SDL_main.h>
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h> 

typedef struct Button{
	Vector2 pos;
	Vector2 size;
}Button;

//Functions
void ButtonClick(Button button, void (*function)());
void SettingsButton();
//EndFunctions

#endif
