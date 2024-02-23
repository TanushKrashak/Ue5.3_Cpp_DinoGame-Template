// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_MainCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"


float trueScore;

// Sets default values
ACpp_MainCharacter::ACpp_MainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	trueScore = 0.0f;

}

// Called when the game starts or when spawned
void ACpp_MainCharacter::BeginPlay()
{
	Super::BeginPlay();
	// Setup Default mapping context
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController())) {
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			SubSystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called every frame
void ACpp_MainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	trueScore += DeltaTime * 100;
	score = FMath::RoundToInt(trueScore);
}

void ACpp_MainCharacter::Duck() {
	// Removes the need to check if char can duck
	if (CanJump()) {
		ACharacter::Crouch(false);
		resizeMesh(true);
	}
}

void ACpp_MainCharacter::StopDuck() {
	ACharacter::UnCrouch(false);
	resizeMesh(false);
}

void ACpp_MainCharacter::charDieAnim_Implementation() {
}

void ACpp_MainCharacter::resizeMesh_Implementation(bool shrink)
{
	// This is a BlueprintNativeEvent, so it needs to be implemented in a blueprint
}


// Called to bind functionality to input
void ACpp_MainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(DuckAction, ETriggerEvent::Triggered, this, &ACpp_MainCharacter::Duck);
		EnhancedInputComponent->BindAction(DuckAction, ETriggerEvent::Completed, this, &ACpp_MainCharacter::StopDuck);
	}

}

void ACpp_MainCharacter::HandleHit() {
	// Disable Player Input and Disable Gravity
	GetCapsuleComponent()->SetSimulatePhysics(true);
	GetCapsuleComponent()->SetEnableGravity(false);

	FVector LaunchImpulse = FVector(0.0f, -2500.0f, 1300.0f);
	GetCapsuleComponent()->AddImpulse(LaunchImpulse, NAME_None, false);
	charDieAnim();
}

