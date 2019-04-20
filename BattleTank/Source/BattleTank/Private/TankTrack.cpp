// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
	// TODO keyboard control is calling both MoveForward and TurnRight each fram
	Throttle = FMath::Clamp<float>(Throttle, -1, 1);
	UE_LOG(LogTemp, Warning, TEXT("Intend TurnRight: %f"), Throttle);
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
