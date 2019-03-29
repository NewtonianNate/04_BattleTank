// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#pragma once

#include "Math/Vector.h"
#include "Engine/World.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last #include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaTime ) override;

private:

	ATank* GetControlledTank() const;
	//Start the tank moving the barrel so that a shot would hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT Parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere) float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere) float CrossHairYLocation = 0.33333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

};
