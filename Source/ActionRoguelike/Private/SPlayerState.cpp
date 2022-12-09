// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerState.h"



void ASPlayerState::AddCredits(int32 Delta)
{

//avoid user-error adding a negative amount/zero
	if (!ensure(Delta > 0.0f))
	{
		return;
	}

	Credits += Delta;

	OnCreditsChanged.Broadcast(this, Credits, Delta);
}

bool ASPlayerState::RemoveCredits(int32 Delta)
{
	//avoid user-error subtracting a negative amount/zero
	if (!ensure(Delta > 0.0))
	{
		return false;
	}
	if (Credits < Delta)
	{
		return false;
	}
		Credits -= Delta;

		OnCreditsChanged.Broadcast(this, Credits, -Delta);

		return true;
	

}

int32 ASPlayerState::GetCredits() const
{
	return Credits;
}