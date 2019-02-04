// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Battletank.h"


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

	UE_LOG(LogTemp, Warning, TEXT("Player Controller is Ticking"))

}

ATank* ATankPlayerController::GetControlledTank() const
{

	 return Cast<ATank>(GetPawn());

 
}
