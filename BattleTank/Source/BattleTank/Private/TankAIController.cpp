// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank *ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}

}


ATank* ATankAIController::GetControlledTank() const
{
	UE_LOG(LogTemp, Warning, TEXT("Getting AI Controlled Tank..."));
	return Cast<ATank>(GetPawn());
}

