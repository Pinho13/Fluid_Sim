#include "Tools.h"

#define numberOfSegments 30
//Constants
const double angleOfSegments = (2 * M_PI) / (numberOfSegments - 1);
//

//Globals
float cosValues[numberOfSegments];
float sinValues[numberOfSegments];
Vector2 mousePos;
//

//Need To Be Innitialized
void GetCosAndSinValues()
{
	for (int i = 0; i < numberOfSegments; i++)
	{
		cosValues[i] = cos(angleOfSegments * i);
		sinValues[i] = sin(angleOfSegments * i);
	}
}
//

//Vectors Stuff
Vector2 AddVectors(Vector2 vector1, Vector2 vector2)
{
	return (Vector2) { vector1.x + vector2.x, vector1.y + vector2.y };
}

Vector2 SubtractVectors(Vector2 vector1, Vector2 vector2)
{
	return (Vector2) { vector1.x - vector2.x, vector1.y - vector2.y };
}

Vector2 MultiplyVectors(Vector2 vector1, Vector2 vector2)
{
	return (Vector2) { vector1.x * vector2.x, vector1.y * vector2.y };
}

Vector2 MultiplyVectorByValue(Vector2 vector1, float value)
{
	return (Vector2) { vector1.x * value, vector1.y * value };
}

Vector2 DivideVectors(Vector2 vector1, Vector2 vector2)
{
	return (Vector2) { vector1.x / vector2.x, vector1.y / vector2.y };
}

Vector2 DivideVectorByValue(Vector2 vector1, int value)
{
	return (Vector2) { vector1.x / value, vector1.y / value };
}

Vector2 NormalizeVector(Vector2 vector1)
{
	float sum;
	if (vector1.x > vector1.y) sum = abs(vector1.x); 
	else sum = abs(vector1.y);
	return (Vector2) { vector1.x / sum, vector1.y / sum };
}

float VectorLength(Vector2 vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

bool CheckIfVecAbsIsSmaller(Vector2 vector1, Vector2 vector2)
{
	if (abs(vector1.x) < vector2.x && abs(vector1.y) < vector2.y) return true;
	else return false;
}
// End Of Vectors Stuff

//Drawing Stuff
void Draw_Rect(SDL_Renderer* renderer, Vector2 pos, Vector2 size, RGBA color)
{
	SDL_Rect rect = { floor(pos.x - (size.x / 2)), floor(pos.y - (size.y / 2)), floor(size.x), floor(size.y)};

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Draw_Fill_Rect(SDL_Renderer* renderer, Vector2 pos, Vector2 size, RGBA color)
{
	SDL_Rect rect = { floor(pos.x - (size.x / 2)), floor(pos.y - (size.y / 2)), size.x, size.y };

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Draw_Circle(SDL_Renderer* renderer, Vector2 pos, int radius, RGBA color)
{
	SDL_Point points[numberOfSegments];
	for (int i = 0; i < numberOfSegments; i++)
	{
		points[i].x = floor((cosValues[i] * radius) + pos.x);
		points[i].y = floor((sinValues[i] * radius) + pos.y);
	}

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLines(renderer, points, numberOfSegments);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
//End Of Drawing Stuff


//Other Stuff
void GetMousePos()
{
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
}

void SeedRandom()
{
	srand(time(NULL));
}

int GetRandomNumber(int num1, int num2)
{
	return (rand() % (num2 - num1 +1) + num1);
}
//End Of Other Stuff