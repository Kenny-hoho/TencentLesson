// Fill out your copyright notice in the Description page of Project Settings.


#include "Stars.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Controller.h"
#include "MyPlayerState.h"

// Sets default values
AStars::AStars()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	RootComponent = SphereComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StarMesh"));
	StaticMeshComponent->SetupAttachment(SphereComponent);
}

void AStars::Interact_Implementation(APawn* InstigatorPawn)
{
	// GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Implementation!"));

	AController* CurrentPlayerController = GetWorld()->GetFirstPlayerController();
	AMyPlayerState* CurrentPlayerState = CurrentPlayerController->GetPlayerState<AMyPlayerState>();
	if (CurrentPlayerState) {
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Last Score: %d"), CurrentPlayerState->MyScore));
		CurrentPlayerState->MyScore++;
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Current Score: %d"), CurrentPlayerState->MyScore));
	}

	Destroy();
}

// Called when the game starts or when spawned
void AStars::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStars::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

