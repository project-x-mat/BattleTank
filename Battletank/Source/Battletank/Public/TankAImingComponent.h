// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAImingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAImingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAImingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);

	void Aimat(FVector HitLocation, float LaunchSpeed);

protected:

	UPROPERTY(BlueprintReadonly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	

	void MoveBarrelTowards(FVector AimDirection);



};
