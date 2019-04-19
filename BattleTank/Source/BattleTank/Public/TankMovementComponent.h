// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankMovementComponent();
	void SetRightTrackReference(UTankTrack* RightTrackToSet);
	void SetLeftTrackReference(UTankTrack* LeftTrackToSet);

	void KeyboardForward();
	void KeyboardReverse();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	UTankTrack* RightTrack = nullptr;
	UTankTrack* LeftTrack = nullptr;
	   	
};
