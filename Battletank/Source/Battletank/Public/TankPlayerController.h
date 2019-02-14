// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

 UFUNCTION(BlueprintCallable, Category = "Setup")
 ATank* GetControlledTank() const;


private:
	

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrossHair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;


	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.4;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
		
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	
};
