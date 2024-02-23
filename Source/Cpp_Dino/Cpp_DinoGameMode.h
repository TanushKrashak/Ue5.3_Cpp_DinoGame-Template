// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Cpp_DinoGameMode.generated.h"

UCLASS(minimalapi)
class ACpp_DinoGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACpp_DinoGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION(BlueprintCallable)
	void SpawnEnemy();
};



