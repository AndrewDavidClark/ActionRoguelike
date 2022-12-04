// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerUpActor.h"
#include "Components/SphereComponent.h"



// Sets default values
ASPowerUpActor::ASPowerUpActor()
{
    SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
    SphereComp->SetCollisionProfileName("Powerup");
    RootComponent = SphereComp;

}

void ASPowerUpActor::Interact_Implementation(APawn* InstigatorPawn)
{
    //logic will come in the derived class...
}


void ASPowerUpActor::ShowPowerup()
{
    SetPowerUpState(true);
}

void ASPowerUpActor::HideAndCooldownPowerup()
{
    SetPowerUpState(false);

    GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &ASPowerUpActor::ShowPowerup, RespawnTime);
}

void ASPowerUpActor::SetPowerUpState(bool bNewIsActive)
{
    SetActorEnableCollision(bNewIsActive);
   

    //set visibility on the root and all children comps
    RootComponent->SetVisibility(bNewIsActive, true);
}

