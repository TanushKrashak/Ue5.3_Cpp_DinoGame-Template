// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cpp_EnemySpawner.generated.h"

UCLASS()
class CPP_DINO_API ACpp_EnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACpp_EnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnEnemy();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<class ACpp_Enemy> EnemyToSpawn;
};
