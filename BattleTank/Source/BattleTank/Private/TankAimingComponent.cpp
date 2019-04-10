// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO Should this really tick?

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}



void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	//Calculate the OutLauncVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false, //this parameter has a default, and so could be omitted
		0.0f, //this parameter has a default, and so could be omitted
		0.0f, //this parameter has a default, and so could be omitted
		ESuggestProjVelocityTraceOption::DoNotTrace, //this parameter has a default, and so could be omitted
		FCollisionResponseParams::DefaultResponseParam, //this parameter can be omitted
		TArray<AActor*>(), //this parameter can be omitted
		true //this parameter can be omitted, set to True for debug path trace
	);
	if (bHaveAimSolution)
	{
		//Turn OutLauncVelocity into unit vector
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		
	}
	else
	{
		return;
	}
	// If no solution found do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//work out difference between current barrel rotation, and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch); // TODO Remove magic number
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time

}
