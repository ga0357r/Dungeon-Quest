// Fill out your copyright notice in the Description page of Project Settings.


#include "GunSpawner.h"


// Sets default values
AGunSpawner::AGunSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGunSpawner::BeginPlay()
{
	Super::BeginPlay();


	//move the reference far away
	//gunReference->SetActorLocation(540.f, 570.f, -120.f);
	//gunReference->SetActorLocation(FVector(540.f, 570.f, -125.f));
}

// Called every frame
void AGunSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//check the gun blueprint
	//if gun blueprint has been picked
	if (manager->gunBlueprintModelHasBeenPicked == true)
	{
		//move gun reference near the player
		//gunReference->SetActorLocation(manager->player->GetActorLocation());

		//make the gun reference a child of player
		//gunReference->SetParent

		
	}
	
}

