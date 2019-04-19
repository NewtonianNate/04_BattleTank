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
class UTankMovementComponent;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BluePrintCallable, Category = Setup) 
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BluePrintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BluePrintCallable, Category = Setup)
		void SetRightTrackReference(UTankTrack* RightTrackToSet);

	UFUNCTION(BluePrintCallable, Category = Setup)
		void SetLeftTrackReference(UTankTrack* LeftTrackToSet);
	
	UFUNCTION(BluePrintCallable)
		void Fire();

	UFUNCTION(BluePrintCallable)
		void KeyboardForward();

	UFUNCTION(BluePrintCallable)
		void KeyboardReverse();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	UTankMovementComponent* TankMovementComponent = nullptr;

private:	
	// Sets default values for this pawn's properties
	ATank();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;
	// TSubclassOf protects against incorrect class selection in: UClass* ProjectileBlueprint; 

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3; // TODO verify this is a good number

	
	// Local barrel reference for spawning barrel projectile
	UTankBarrel* Barrel = nullptr;

	
	double LastFireTime = 0;

};
