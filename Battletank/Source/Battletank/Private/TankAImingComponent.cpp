// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAImingComponent.h"

// Sets default values for this component's properties
UTankAImingComponent::UTankAImingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAImingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAImingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



// Called every frame
void UTankAImingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAImingComponent::Aimat(FVector HitLocation)
{
	auto OurTankName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT(" %s is aiming at  %s"), *OurTankName, *HitLocation.ToString());

}

