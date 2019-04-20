// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// +1 is max forward speed, -1 is max reverse speed
	void Move(float RelativeSpeed);
	// Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxForwardSpeed = 10;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxReverseSpeed = 5;
	
	// This is max force per track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float TrackMaxDrivingForce = 400000; // Assume 40 tonne tankand 1g acceleration

};
