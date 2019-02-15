// Fill out your copyright notice in the Description page of Project Settings.




#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTacktoset) 
{
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTacktoset;

}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForeMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AiForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AiForwardIntention);

	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AiForwardIntention).Z;
	IntendTurnRight(RightThrow);

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack || RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack || RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

}


