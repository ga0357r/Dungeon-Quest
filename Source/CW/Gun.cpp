// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();

	TurnObjectOff();

	//player = GetWorld->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Turn Object Off
void AGun::TurnObjectOff()
{
	//disable collision
	SetActorEnableCollision(false);

	//disable ticking for this object


	//hide the object
	//SetActorHiddenInGame(true);
}

