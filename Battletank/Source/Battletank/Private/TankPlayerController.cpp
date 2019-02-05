// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Battletank.h"
#include "Engine.h"


void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller not possesing a Tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is  possesed by Human"), *(ControlledTank->GetName()));

	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrossHair();
		
}

ATank* ATankPlayerController::GetControlledTank() const
{

	 return Cast<ATank>(GetPawn());

 
}

void ATankPlayerController::AimTowardsCrossHair() {

	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{

		GetControlledTank()->Aimat(HitLocation);

	}
}


	bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
	{
		int32 ViewportSizeX, VeiwportSizeY;
		GetViewportSize(ViewportSizeX, VeiwportSizeY);
		auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, VeiwportSizeY * CrosshairYLocation);

		FVector LookDirection;
		if (GetLookDirection(ScreenLocation, LookDirection))
		{
			GetLookVectorHitLocation(LookDirection, HitLocation);
		}
		

		return true;

	}

	bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
	{
		FVector CameraWorldLocation;
		return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

	}

	bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const 
	{
		FHitResult HitResult;
		auto StartLocation = PlayerCameraManager->GetCameraLocation();
		auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
		{
			HitLocation = HitResult.Location;
			return true;
		}
		return false;
	}
	


