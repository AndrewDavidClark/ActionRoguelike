// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_ExplosiveBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AAC_ExplosiveBarrel::AAC_ExplosiveBarrel()
{
	//Mesh Setup
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");//create instance of mesh component	
	MeshComp->SetSimulatePhysics(true);//set simulate physics true	
	MeshComp->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);//set collision profile to PhysicsActor	
	RootComponent = MeshComp;//assign mesh to root

	//RadialForce Setup
	ForceComp = CreateDefaultSubobject<URadialForceComponent>("ForceComp");//create instance of radial force component
	ForceComp->SetupAttachment(MeshComp);//attach radial force component to mesh component
	ForceComp->SetAutoActivate(false);//Removes default tick force apply

	//RadialForce Default Variables
	ForceComp->Radius = 750.0f;//radius of ForceComp
	ForceComp->ImpulseStrength = 2500.0f; //strength of ForceComp
	ForceComp->bImpulseVelChange = true;//ignores mass of other objects(will require higher strength if false)

	//Default collision channel
	ForceComp->AddCollisionChannelToAffect(ECC_WorldDynamic);





 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



void AAC_ExplosiveBarrel::Interact_Implementation(APawn* InstigatorPawn)
{
	//MeshComp->SetRelativeRotation(FRotator(110, 0, 0));
	ForceComp->FireImpulse();
	UE_LOG(LogTemp, Log, TEXT("Shouldhaveblown"));
}

void AAC_ExplosiveBarrel::PostInitializeComponents()
{
	//Calls parent function
	Super::PostInitializeComponents();

	MeshComp->OnComponentHit.AddDynamic(this, &AAC_ExplosiveBarrel::OnActorHit);
}

// Called when the game starts or when spawned
void AAC_ExplosiveBarrel::BeginPlay()
{
	

	Super::BeginPlay();
	
}

void AAC_ExplosiveBarrel::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ForceComp->FireImpulse();
	
	UE_LOG(LogTemp, Log, TEXT("OnActorHit in Explosive Barrel"));

	// %s = string
	// %f = float
	// logs: "OtherActor: MyActor_1, at gametime: 124.4" 
	UE_LOG(LogTemp, Warning, TEXT("OtherActor: %s, at game time: %f"), *GetNameSafe(OtherActor), GetWorld()->TimeSeconds);

	FString CombinedString = FString::Printf(TEXT("Hit at location: %s"), *Hit.ImpactPoint.ToString());
	DrawDebugString(GetWorld(), Hit.ImpactPoint, CombinedString, nullptr, FColor::Green, 2.0f, true);
}

// Called every frame
void AAC_ExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

