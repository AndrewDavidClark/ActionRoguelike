// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AC_GameplayInterface.h"
#include "AC_ItemChest.generated.h"


class UStaticMeshComponent;

UCLASS()
class ACTIONROGUELIKE_API AAC_ItemChest : public AActor, public IAC_GameplayInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		float TargetPitch;

		void Interact_Implementation(APawn* InstigatorPawn);
	
public:	
	// Sets default values for this actor's properties
	AAC_ItemChest();

protected:

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;//Adds mesh comp 1
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* LidMesh;//Adds mesh comp 2

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	};
