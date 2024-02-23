// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cpp_DinoGameMode.h"
#include "Cpp_DinoCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Cpp_EnemySpawner.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

TArray<AActor*> mySpawners;

ACpp_DinoGameMode::ACpp_DinoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ACpp_DinoGameMode::BeginPlay() {
	Super::BeginPlay();
	//Get all the enemy spawners
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACpp_EnemySpawner::StaticClass(), mySpawners);
}

void ACpp_DinoGameMode::SpawnEnemy() {
	UE_LOG(LogTemp, Warning, TEXT("Spawning Enemy"));
	// Spawn an enemy from a random spawner
	Cast<ACpp_EnemySpawner>(mySpawners[FMath::RandRange(0, mySpawners.Num()-1)])->SpawnEnemy();
}
