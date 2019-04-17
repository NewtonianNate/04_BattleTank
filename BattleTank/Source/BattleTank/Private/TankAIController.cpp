// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.


#include "TankAIController.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	if (!ControlledTank) { return; }
	if (!PlayerTank) { return; }

	// TODO move towards the player

	// Aim Towards the player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	// Fire if ready
	ControlledTank->Fire(); // TODO limit firing rate

}

