// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_Enemy.h"
#include "Components/BoxComponent.h"
#include "Cpp_MainCharacter.h"

// Sets default values
ACpp_Enemy::ACpp_Enemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up the box collision & set it as the root component
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = BoxComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Collision"));
	BaseMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACpp_Enemy::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ACpp_Enemy::OnOverlapStart);
	moveSpeed = baseSpeed - (GetWorld()->GetTimeSeconds() * 10);
}

// Called every frame
void ACpp_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Move the enemy w.r.to the DeltaTime
	if (RootComponent) {
		FVector DeltaLocation = FVector(0.0f, 0.0f, 0.0f);
		DeltaLocation.Y = moveSpeed * DeltaTime;
		RootComponent->SetWorldLocation(RootComponent->GetComponentLocation() + DeltaLocation);

		// Destroy the enemy if it goes out of the screen
		if (RootComponent->GetComponentLocation().Y < -1500.0f) {
			Destroy();
		}		
	}
}

// Called when the enemy overlaps with another actor
void ACpp_Enemy::OnOverlapStart(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	ACpp_MainCharacter* Player = Cast<ACpp_MainCharacter>(OtherActor);
	// If the other actor is the player, call the HandleHit function
	if (Player != nullptr) {
		Player->HandleHit();
	}
}


