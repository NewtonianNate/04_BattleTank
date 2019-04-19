// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#include "TankMovementComponent.h"
#include "TankTrack.h"


// Sets default values for this component's properties
UTankMovementComponent::UTankMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankMovementComponent::SetRightTrackReference(UTankTrack* RightTrackToSet)
{
	if (!RightTrackToSet) { return; }

	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::SetLeftTrackReference(UTankTrack* LeftTrackToSet)
{
	if (!LeftTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
}


void UTankMovementComponent::KeyboardForward()
{
	UE_LOG(LogTemp, Warning, TEXT("RightTrack:"));
	RightTrack->Move(1.0);
	UE_LOG(LogTemp, Warning, TEXT("LeftTrack:"));
	LeftTrack->Move(1.0);
	
}

void UTankMovementComponent::KeyboardReverse()
{
	UE_LOG(LogTemp, Warning, TEXT("RightTrack:"));
	RightTrack->Move(-1.0);
	UE_LOG(LogTemp, Warning, TEXT("LeftTrack:"));
	LeftTrack->Move(-1.0);
}

