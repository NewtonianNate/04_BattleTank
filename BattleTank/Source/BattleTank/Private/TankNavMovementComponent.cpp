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
	if (!ensure(RightTrack && LeftTrack)) { return; }
	RightTrack->SetThrottle(Throw);
	LeftTrack->SetThrottle(Throw);
}

void UTankNavMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(RightTrack && LeftTrack)) { return; }
	RightTrack->SetThrottle(-Throw);
	LeftTrack->SetThrottle(Throw);
}

/** path following: request new velocity */
void UTankNavMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super() as we're replacing the functionality
	

	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	IntendMoveForward(FVector::DotProduct(TankForward, AIForwardIntention));
	IntendTurnRight(FVector::CrossProduct(TankForward, AIForwardIntention).Z);
	
	/*
	auto Name = GetOwner()->GetName();
	auto ForwardS = AIForwardIntention.ToString();
	auto Turnright = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	UE_LOG(LogTemp, Warning, TEXT("%s Forward: %s"), *Name, *ForwardS);
	UE_LOG(LogTemp, Warning, TEXT("%s Vectoring to: %f"), *Name, Turnright);
	*/

	//UE_LOG(LogTemp, Warning, TEXT("%s Vectoring to: %s"), *TankName, *MoveVelocityString);
}
