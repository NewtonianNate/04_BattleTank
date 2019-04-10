// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

 //Forward declaration
class UTankBarrel;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	// TODO add SetTurretRefrence
	void AimAt(FVector HitLocation, float LaunchSpeed);


private:	
	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};