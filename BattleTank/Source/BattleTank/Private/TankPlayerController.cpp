// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Math/Vector.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h" // TODO delete this after debugline is no longer needed


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();

}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; } //eg. if not possessing
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector OutHitLocation; // Out parameter
	if (GetSightRayHitLocation(OutHitLocation)) // Has "side-effect", is going to line trace
	{
		AimingComponent->AimAt(OutHitLocation);
	}
	
	  
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find Crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(CrossHairXLocation * ViewportSizeX, CrossHairYLocation * ViewportSizeY);
	
	// "de-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	FVector LookLocation;
	if (GetLookDirection(ScreenLocation, LookLocation, LookDirection))
	{
		//Line-trace along that direction, and see what we hit (up to max range)
		return GetLookVectorHitLocation(LookLocation, LookDirection, OutHitLocation);
	}
		
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookLocation, FVector& LookDirection) const
{
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		LookLocation,
		LookDirection);
	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookLocation, FVector LookDirection, FVector &OutHitLocation) const
{
	FHitResult HitResult;
	FVector LineTraceEnd = LookLocation + ( LookDirection * LineTraceRange );
	
	//DrawDebugLine(GetWorld(), LookLocation, LineTraceEnd, FColor::Green, false, 0, 0, 1); // TODO delete this after debugging
	
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult, 
		LookLocation, 
		LineTraceEnd, 
		ECC_Visibility)
		)
	{
		OutHitLocation = HitResult.ImpactPoint;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}