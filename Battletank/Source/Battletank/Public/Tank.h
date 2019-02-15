// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

		

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();



private:

	// Sets default values for this pawn's properties
	ATank();


	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 100000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;


	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;
	
	double LastFireTime = 0;

};
