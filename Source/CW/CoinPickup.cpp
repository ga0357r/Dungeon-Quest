// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPickup.h"

// Sets default values
ACoinPickup::ACoinPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoinPickup::BeginPlay()
{
	Super::BeginPlay();
	
	//find the Player Character
	player = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void ACoinPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//if  the player character is in the volume
	if (coinPickupTrigger->IsOverlappingActor(player))
	{
		// pick up coin  
		PickupCoin();
	}
}



void ACoinPickup::PickupCoin()
{
	// Draw the Player healthbar.
	AMyFirstPersonCharacter* _player = Cast<AMyFirstPersonCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	//increase the total coins of the player by 1
	_player->totalCoins += 1;

	UE_LOG(LogTemp, Warning, TEXT("Pickup Coin"));

	//turn off collision
	SetActorEnableCollision(false);

	//stop running every frame
	SetActorTickEnabled(false);

	//disable this actor
	SetActorHiddenInGame(true);

	//disable the trigger

	//turn off collision
	coinPickupTrigger->SetActorEnableCollision(false);

	//turn the pickup trigger off
	coinPickupTrigger->SetActorTickEnabled(false);

	//disable this actor
	coinPickupTrigger->SetActorHiddenInGame(true);
}

