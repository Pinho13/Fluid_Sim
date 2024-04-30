#pragma once
#include <stdint.h>
#include <math.h>
#include <SDL_main.h>
#include <SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector2{
	int x, y;
}Vector2;

typedef struct RGBA{
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
Vector2 MultiplyVectorByValue(Vector2 vector1, int value);
Vector2 DivideVectors(Vector2 vector1, Vector2 vector2);
Vector2 DivideVectorByValue(Vector2 vector1, int value);
Vector2 NormalizeVector(Vector2 vector1);

float VectorLength(Vector2 vector);
bool CheckIfVecAbsIsSmaller(Vector2 vector1, Vector2 vector2);
 //EndVectors

 //Drawing
void Draw_Rect(SDL_Renderer* renderer, Vector2 pos, Vector2 size, RGBA color);
void Draw_Fill_Rect(SDL_Renderer* renderer, Vector2 pos, Vector2 size, RGBA color);
void Draw_Circle(SDL_Renderer* renderer, Vector2 pos, int radius, RGBA color);
 //EndDrawing
 
 //Others
void GetMousePos();
void SeedRandom();
int GetRandomNumber(int num1, int num2);
 //EndOthers
//EndFuncs

///COLORS
static const RGBA WHITE = { 255, 255, 255, 255 };
static const RGBA BLACK = { 0, 0, 0, 255 };
static const RGBA RED = { 255, 0, 0, 255 };
static const RGBA GREEN = { 0, 255, 0, 255 };
static const RGBA BLUE = { 0, 0, 255, 255 };





