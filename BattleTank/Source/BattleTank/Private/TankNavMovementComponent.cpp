// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#include "TankNavMovementComponent.h"
#include "TankTrack.h"


void UTankNavMovementComponent::Initialise(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet)
{
	RightTrack = RightTrackToSet;
	LeftTrack = LeftTrackToSet;
}


void UTankNavMovementComponent::IntendMoveForward(float Throw)
{
	if (!RightTrack || !LeftTrack) { return; }
	RightTrack->SetThrottle(Throw);
	LeftTrack->SetThrottle(Throw);
}

void UTankNavMovementComponent::IntendTurnRight(float Throw)
{
	if (!RightTrack || !LeftTrack) { return; }
	RightTrack->SetThrottle(-Throw);
	LeftTrack->SetThrottle(Throw);
}
