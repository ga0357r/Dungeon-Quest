// Fill out your copyright notice in the Description page of Project Settings.


#include "DangerousObject.h"

// Sets default values
ADangerousObject::ADangerousObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADangerousObject::BeginPlay()
{
	Super::BeginPlay();
	
	//find the Player Character
	player = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void ADangerousObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//if  the player character is in the volume
	if (applyDamageTrigger->IsOverlappingActor(player))
	{
		// apply damage to the player
		DamagePlayer();
	}
}


void ADangerousObject::DamagePlayer()
{
	// Draw the Player healthbar.
	AMyFirstPersonCharacter* _player = Cast<AMyFirstPersonCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	//increase the total coins of the player by 1
	_player->Hp -= 35;

	UE_LOG(LogTemp, Warning, TEXT("Dealt damage to player"));
}
