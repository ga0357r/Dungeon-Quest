// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGun_ActorComponent.h"



// Sets default values for this component's properties
UMyGun_ActorComponent::UMyGun_ActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyGun_ActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	//find the Player Character
	player = GetWorld()->GetFirstPlayerController()->GetPawn();
	//add the player character to the player trigger volume
	
}


// Called every frame
void UMyGun_ActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	//if  the player character is in the volume
	if (gunPickupTrigger->IsOverlappingActor(player))
	{
		// pick up gun  
		PickupGun();
	}

	
}

void UMyGun_ActorComponent::PickupGun()
{
	UE_LOG(LogTemp, Warning, TEXT("Pickup Gun"));

	//This gun should be hidden
	HasBeenPicked = true;

	if (HasBeenPicked)
	{
		
		//disable its collision
		GetOwner()->SetActorEnableCollision(false);

		//disable it from ticking
		GetOwner()->SetActorTickEnabled(false);

		//hide it in the game
		GetOwner()->SetActorHiddenInGame(true);
	
	}

}


bool UMyGun_ActorComponent::GetValueOf_HasBeenPicked()
{
	return HasBeenPicked;
}
