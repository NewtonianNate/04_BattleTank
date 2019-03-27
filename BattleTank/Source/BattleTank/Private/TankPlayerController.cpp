// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank *ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();

}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; // Out parameter
	if (GetSightRayHitLocation(OutHitLocation)) // Has "side-effect", is going to ray trace
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *OutHitLocation.ToString());

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Hitting Landscape"));
	}
	
	  // TODO Tell controlled tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//bool World = true;

	OutHitLocation = FVector(1.0);
	//OutHitLocation = GetWorld()->GetFirstPlayerController->GetFocalLocation();

	return true;
}