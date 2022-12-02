// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "AC_ExplosiveBarrel.generated.h"


//declarations
class URadialForceComponent;
class UStaticMeshComponent;


UCLASS()
class ACTIONROGUELIKE_API AAC_ExplosiveBarrel : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAC_ExplosiveBarrel();

protected:
	//Adds Mesh Component
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshComp;
	//Adds Force Component
	UPROPERTY(VisibleAnywhere)
		URadialForceComponent* ForceComp;

	//UFUNCTION(BlueprintCallable)
		void Interact_Implementation(APawn* InstigatorPawn);

	virtual void PostInitializeComponents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UFUNCTION "binds" the event
	UFUNCTION()
		void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
