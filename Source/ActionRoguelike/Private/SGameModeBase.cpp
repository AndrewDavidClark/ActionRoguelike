// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameModeBase.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include <AI/SAICharacter.h>
#include <SAttributeComponent.h>
#include <EngineUtils.h>
#include <DrawDebugHelpers.h>



ASGameModeBase::ASGameModeBase()
{
	SpawnTimerInterval = 2.0f;
}

void ASGameModeBase::StartPlay()
{
	Super::StartPlay();

	//Continuous timer to spawn in more bots.
	//Actual amount of bots and if its allowed to spawn the bots is determined by spawn logic later in the chain.
	GetWorldTimerManager().SetTimer(TimerHandle_SpawnBots, this, &ASGameModeBase::SpawnBotTimerElapsed, SpawnTimerInterval, true);
}

void ASGameModeBase::SpawnBotTimerElapsed()
{
	int32 NrOfAliveBots = 0;
	for (TActorIterator<ASAICharacter> It(GetWorld()); It; ++It)//Grabs any instances of a particular class(ASAICharacter) --VERY USEFUL c++ variant of GetAllActorOfClass(BP Node)
	{
		ASAICharacter* Bot = *It;

		USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(Bot->GetComponentByClass(USAttributeComponent::StaticClass()));
		if (ensure(AttributeComp) && AttributeComp->IsAlive())
		{
			NrOfAliveBots++;
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Found %i alive bots."), NrOfAliveBots);

	float MaxBotCount = 10.0f;

	if (DifficultyCurve)
	{
		MaxBotCount = DifficultyCurve->GetFloatValue(GetWorld()->TimeSeconds);
	}

	if (NrOfAliveBots >= MaxBotCount)
	{
		UE_LOG(LogTemp, Log, TEXT("At max bot capacity. Skip bot spawn."));
		return;
	}

	UEnvQueryInstanceBlueprintWrapper* QueryInstance = UEnvQueryManager::RunEQSQuery(this, SpawnBotQuery, this, EEnvQueryRunMode::RandomBest5Pct, nullptr);//Run EQS Query
	if (ensure(QueryInstance))
	{
		QueryInstance->GetOnQueryFinishedEvent().AddDynamic(this, &ASGameModeBase::OnQueryCompleted);//Event on EQS Query Finish
	}


}

void ASGameModeBase::OnQueryCompleted(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus)//Triggers after Query Finished and spawns the bot
{
	if (QueryStatus != EEnvQueryStatus::Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawn bot EQS Query Failed!"));
		return;
	}

	

	

	TArray<FVector> Locations = QueryInstance->GetResultsAsLocations();

	if (Locations.Num() > 0)
	{

		GetWorld()->SpawnActor<AActor>(MinionClass, Locations[0], FRotator::ZeroRotator);//Use successful EQS query and spawn MinionClass

		//Track all of the used spawn locations
		DrawDebugSphere(GetWorld(), Locations[0], 50.0f, 20, FColor::Blue, false, 60.0f);
	}
}

