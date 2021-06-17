// Fill out your copyright notice in the Description page of Project Settings.


#include "Model_Gun.h"

// Sets default values
AModel_Gun::AModel_Gun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AModel_Gun::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AModel_Gun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
