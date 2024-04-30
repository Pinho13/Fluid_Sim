#include "UI.h"
#include "Fluid_Sim.h"
#include "Tools.h"

extern Vector2 mousePos;
static bool hasWindowOpen;

void ButtonClick(Button button, void (*function)())
{
	Vector2 dist = SubtractVectors(mousePos, button.pos);
	if (CheckIfVecAbsIsSmaller(dist, button.size))
	{
		(*function)();
	}
}

void SettingsButton()
{

}
