// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_ItemChest.h"

#include "Components/StaticMeshComponent.h"

void AAC_ItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));

}

// Sets default values
AAC_ItemChest::AAC_ItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));//create instance of mesh component
	RootComponent = BaseMesh;//assign mesh to root

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));//create instance of mesh component
	LidMesh->SetupAttachment(BaseMesh);//attach lid to base

	TargetPitch = 110;

}

// Called when the game starts or when spawned
void AAC_ItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAC_ItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

