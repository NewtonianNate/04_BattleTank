// This game is copyright of Awny Betts. Based on Ben Tristem Unreal C++ Developer course.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Note: must be last #include

// Forward declarations
class UTankBarrel; 
class UTankTurret;
class AProjectile;
class UTankTrack;
class UTankAimingComponent;
class UTankNavMovementComponent;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	
	UFUNCTION(BluePrintCallable, Category = "Setup")
		void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankNavMovementComponent* TankNavMovementComponent = nullptr;

private:	
	virtual void BeginPlay() override;
	// Sets default values for this pawn's properties
	ATank();
	

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	// TSubclassOf protects against incorrect class selection in: UClass* ProjectileBlueprint; 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3; // TODO verify this is a good number
		
	// Loacal Barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO remove

	double LastFireTime = 0;

};
