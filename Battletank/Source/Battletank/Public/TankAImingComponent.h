// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAImingComponent.generated.h"

class UTankBarrel;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAImingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAImingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);


	void Aimat(FVector HitLocation, float LaunchSpeed);

private:

	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

};