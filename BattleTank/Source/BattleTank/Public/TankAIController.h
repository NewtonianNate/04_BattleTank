// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#pragma once

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
	
protected:
	//How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 80000;

private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	
private:

};
