// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


public:
	ATank* GetControlledTank() const;

	
	ATank* GetPlayerTank() const;
	
};
