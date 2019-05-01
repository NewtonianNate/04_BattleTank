// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.


#include "TankAIController.h"
#include "TankAimingComponent.h"
// Depends on movement component via pathfindign system


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
		
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in centimeters

	// Aim Towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// Fire if ready
	AimingComponent->Fire(); // TODO limit firing rate

}

