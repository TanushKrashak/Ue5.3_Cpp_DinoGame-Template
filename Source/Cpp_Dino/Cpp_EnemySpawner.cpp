// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_EnemySpawner.h"
#include "Cpp_Enemy.h"

// Sets default values
ACpp_EnemySpawner::ACpp_EnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACpp_EnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACpp_EnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACpp_EnemySpawner::SpawnEnemy() {
	// Spawn the enemy at the location of the spawner
	ACpp_Enemy *Enemy = GetWorld()->SpawnActor<ACpp_Enemy>(EnemyToSpawn, GetActorLocation(), GetActorRotation());
}

