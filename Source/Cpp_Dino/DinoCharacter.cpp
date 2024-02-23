// Fill out your copyright notice in the Description page of Project Settings.


#include "DinoCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"

// Sets default values
ADinoCharacter::ADinoCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADinoCharacter::BeginPlay()
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
void ADinoCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADinoCharacter::Duck() {
	UE_LOG(LogTemp, Warning, TEXT("Duck"));
}

void ADinoCharacter::Jumping() {
	UE_LOG(LogTemp, Warning, TEXT("Jump"));
}

// Called to bind functionality to input
void ADinoCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ADinoCharacter::Jumping);
		EnhancedInputComponent->BindAction(DuckAction, ETriggerEvent::Triggered, this, &ADinoCharacter::Duck);
	}
}

