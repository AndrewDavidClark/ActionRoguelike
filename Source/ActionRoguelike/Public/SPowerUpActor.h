// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "SPowerUpActor.generated.h"

class USphereComponent;

UCLASS()
class ACTIONROGUELIKE_API ASPowerUpActor : public AActor, public ISGameplayInterface//Dont forget to implement GameplayInterface
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditAnywhere, Category = "PowerUp")
	float RespawnTime;

	FTimerHandle TimerHandle_RespawnTimer;

	UFUNCTION()
	void ShowPowerup();

	void HideAndCooldownPowerup();

	void SetPowerUpState(bool bNewIsActive);

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MeshComp;

public:	

	void Interact_Implementation(APawn* InstigatorPawn) override;

	// Sets default values for this actor's properties
	ASPowerUpActor();


};
