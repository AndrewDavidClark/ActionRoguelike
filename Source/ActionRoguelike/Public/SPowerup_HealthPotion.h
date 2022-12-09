// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SPowerUpActor.h"
#include "SPowerup_HealthPotion.generated.h"

class UStaticMeshComponent;
/**
 *
 */
UCLASS()
class ACTIONROGUELIKE_API ASPowerup_HealthPotion : public ASPowerUpActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "HealthPotion")
		int32 CreditCost;

	//float health amount???????

public:
	void Interact_Implementation(APawn* InstigatorPawn) override;

	ASPowerup_HealthPotion();


};
