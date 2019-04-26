// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last #include

// Forward declaration
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;


private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//Start the tank moving the barrel so that a shot would hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT Parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly) float CrossHairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly) float CrossHairYLocation = 0.33333f;
	UPROPERTY(EditDefaultsOnly) float LineTraceRange = 1000000.f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookLocation, FVector LookDirection, FVector &OutHitLocation) const;
};
