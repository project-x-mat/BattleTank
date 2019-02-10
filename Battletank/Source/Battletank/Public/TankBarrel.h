// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDgreesPerSecond = 5;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevationDgrees = 30;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevationDgrees = 0;
};
