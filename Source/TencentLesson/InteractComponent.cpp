// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"
#include "Interact_Interface.h"
#include "Components/CapsuleComponent.h"
#include "MyCharacter.h"

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	AMyCharacter* PlayerChar = Cast<AMyCharacter>(GetOwner());
	if (PlayerChar) {
		PlayerChar->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &UInteractComponent::ComponentBeginOverlap);
	}
}

// Called when the game starts
void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// 组件重叠时调用基础交互函数
void UInteractComponent::ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, FString::Printf(TEXT("BeginOverlap")));
	Primary_Interact(OtherActor);
}

void UInteractComponent::Primary_Interact(AActor* InteractActor)
{
	AMyCharacter* PlayerChar = Cast<AMyCharacter>(GetOwner());
	if (PlayerChar) {
		if (InteractActor->Implements<UInteract_Interface>()) {
			IInteract_Interface::Execute_Interact(InteractActor, PlayerChar);
		}
	}
}

