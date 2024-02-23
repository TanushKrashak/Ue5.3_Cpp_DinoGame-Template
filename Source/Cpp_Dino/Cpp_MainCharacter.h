// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Cpp_MainCharacter.generated.h"

UCLASS()
class CPP_DINO_API ACpp_MainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACpp_MainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void HandleHit();

private:
	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* DuckAction;

	// Called When DuckAction is pressed	
	void Duck();
	// Called When DuckAction is released
	void StopDuck();

public:
	UPROPERTY(BlueprintReadOnly, Category = "Score")
	int score = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mesh")
	void resizeMesh(bool shrink);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mesh")
	void charDieAnim();
};
