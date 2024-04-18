#include "Tools.h"

#define numberOfSegments 30

const double angleOfSegments = (2 * M_PI) / (numberOfSegments - 1);
float cosValues[numberOfSegments];
float sinValues[numberOfSegments];

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

Vector2 DivideVectors(Vector2 vector1, Vector2 vector2)
{
	return (Vector2) { vector1.x / vector2.x, vector1.y / vector2.y };
}

float VectorLength(Vector2 vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}
// End Of Vectors Stuff

//Drawing Stuff
void Draw_Rect(SDL_Renderer* renderer, Vector2 pos, Vector2 size, RGBA color)
{
	SDL_Rect rect = { pos.x, pos.y, size.x, size.y };

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Draw_Circle(SDL_Renderer* renderer, Vector2 pos, int radius, RGBA color)
{
	SDL_Point points[numberOfSegments];
	for (int i = 0; i < numberOfSegments; i++)
	{
		points[i].x = round((cosValues[i] * radius) + pos.x);
		points[i].y = round((sinValues[i] * radius) + pos.y);
	}

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLines(renderer, points, numberOfSegments);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
//End Of Drawing Stuff


//Other Stuff
Vector2 GetMousePos()
{
	Vector2 vec;
	SDL_GetMouseState(&vec.x, &vec.y);
	return vec;
}
//End Of Other Stuff