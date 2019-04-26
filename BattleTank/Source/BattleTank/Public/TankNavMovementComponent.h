// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankNavMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible for driving the tank tracks
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankNavMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BluePrintCallable, Category = "Setup")
		void Initialise(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet);

	UFUNCTION(BluePrintCallable, Category = "Input")
		void IntendMoveForward(float Throw);

	UFUNCTION(BluePrintCallable, Category = "Input")
		void IntendTurnRight(float Throw);
	
	
private:
	/** path following: request new velocity */
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	
	UTankTrack* RightTrack = nullptr;
	UTankTrack* LeftTrack = nullptr;
	
	
	
};
