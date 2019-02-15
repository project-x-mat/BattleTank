// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAImingComponent.h"
#include "Engine.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }


	MoveToActor(PlayerTank, AcceptanceRadius);

	auto AimingComponent = ControlledTank->FindComponentByClass <UTankAImingComponent>();
	AimingComponent->Aimat(PlayerTank->GetActorLocation());
		
	//ControlledTank->Fire();

	
	
}




