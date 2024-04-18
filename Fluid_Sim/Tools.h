#pragma once
#ifndef TOOLS_H
#define TOOLS_H
#include <stdint.h>
#include <math.h>
#include <SDL_main.h>
#include <SDL.h>

typedef struct {
	int x, y;
}Vector2;

typedef struct {
	uint8_t r, g, b, a;
}RGBA;

//Funcs
 //Initialization
void GetCosAndSinValues();
 // 
 //Vectors
Vector2 AddVectors(Vector2 vector1, Vector2 vector2);
Vector2 SubtractVectors(Vector2 vector1, Vector2 vector2);
Vector2 MultiplyVectors(Vector2 vector1, Vector2 vector2);
Vector2 DivideVectors(Vector2 vector1, Vector2 vector2);
float VectorLength(Vector2 vector);
 //EndVectors

 //Drawing
void Draw_Rect(SDL_Renderer* renderer, Vector2 pos, Vector2 size, RGBA color);
void Draw_Circle(SDL_Renderer* renderer, Vector2 pos, int radius, RGBA color);
 //EndDrawing
 
 //Others
Vector2 GetMousePos();
 //EndOthers
//EndFuncs

///COLORS
static const RGBA WHITE = { 255, 255, 255, 255 };
static const RGBA BLACK = { 0, 0, 0, 255 };
static const RGBA RED = { 255, 0, 0, 255 };
static const RGBA GREEN = { 0, 255, 0, 255 };
static const RGBA BLUE = { 0, 0, 255, 255 };






#endif // !TOOLS_H
