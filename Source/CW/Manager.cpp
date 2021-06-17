// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager.h"

// Sets default values
AManager::AManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AManager::BeginPlay()
{
	Super::BeginPlay();
	
	//find the Player Character
	player = GetWorld()->GetFirstPlayerController()->GetPawn();
	//add the player character to the player trigger volume

}

// Called every frame
void AManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if  the player character is in the volume
	if (gunPickupTrigger->IsOverlappingActor(player))
	{
		// pick up gun  
		PickupGun();
	}

}



void AManager::PickupGun()
{
	UE_LOG(LogTemp, Warning, TEXT("Pickup Gun"));

	//This gun should be hidden
	gunBlueprintModelHasBeenPicked = true;

	if (gunBlueprintModelHasBeenPicked)
	{

		//disable its collision
		gunModelBlueprint->SetActorEnableCollision(false);

		//disable it from ticking
		gunModelBlueprint->SetActorTickEnabled(false);

		//hide it in the game
		gunModelBlueprint->SetActorHiddenInGame(true);



	}

}
