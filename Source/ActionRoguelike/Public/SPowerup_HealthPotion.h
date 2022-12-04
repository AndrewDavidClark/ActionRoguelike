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
class ACTIONROGUELIKE_API ASPowerup_HeatlhPotion : public ASPowerUpActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MeshComp;

	//float health amount???????

public:
	void Interact_Implementation(APawn* InstigatorPawn) override;

	ASPowerup_HeatlhPotion();


};
