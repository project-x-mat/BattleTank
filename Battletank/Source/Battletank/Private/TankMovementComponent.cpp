// Fill out your copyright notice in the Description page of Project Settings.




#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTacktoset) 
{
	if (!LeftTrackToSet || !RightTacktoset) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTacktoset;

}



void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

}