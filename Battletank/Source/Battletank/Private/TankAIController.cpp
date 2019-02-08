// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "Engine.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller not possesing a Tank"));
	}
	else
	{

		UE_LOG(LogTemp, Warning, TEXT("%s is  possesed by AI"), *(ControlledTank->GetName()));
	}


	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) 
	{
		
		GetControlledTank() ->Aimat(GetPlayerTank()->GetActorLocation());
	}
	
}


ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());


}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	   
	if (!PlayerPawn) 
	{ return nullptr; } // Note the !, very important
	   
	return Cast<ATank>(PlayerPawn);
}