// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interact_Interface.h"
#include "Stars.generated.h"

UCLASS()
class TENCENTLESSON_API AStars : public AActor, public IInteract_Interface
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	class USphereComponent* SphereComponent;
public:	
	// Sets default values for this actor's properties
	AStars();

	void Interact_Implementation(APawn* InstigatorPawn);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
