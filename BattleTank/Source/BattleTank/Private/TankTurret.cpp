// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	//Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}

