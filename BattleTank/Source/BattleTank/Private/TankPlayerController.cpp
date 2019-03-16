// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#include "TankPlayerController.h"




ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}