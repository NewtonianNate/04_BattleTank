// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#pragma once

#include "Math/Rotator.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */

//Tank Barrel Component
UCLASS(meta = (BlueprintSpawnableComponent))//, hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, and +1 is max upward movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 10; // Sensible default
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevationDegrees = 40; //Sensible default
		
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevationDegrees = 0; //Sensible default


};
