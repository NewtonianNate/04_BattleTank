// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#include "TankTrack.h"



void UTankTrack::Move(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	if (RelativeSpeed > 0)
	{
		float DeltaPosition = RelativeSpeed * MaxForwardSpeed * GetWorld()->DeltaTimeSeconds;
		//auto NewPosition = RelativeLocation.ForwardVector + DeltaPosition;
		//SetRelativeLocation(NewPosition);
		UE_LOG(LogTemp, Warning, TEXT("Moving forward at %f"), DeltaPosition);
	
	}
	else
	{
		float DeltaPosition = RelativeSpeed * MaxReverseSpeed * GetWorld()->DeltaTimeSeconds;
		UE_LOG(LogTemp, Warning, TEXT("Moving reverse at %f"), DeltaPosition);
	}

}

void UTankTrack::SetThrottle(float Throttle)
{
	FString Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	// TODO Clamp throttle

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
