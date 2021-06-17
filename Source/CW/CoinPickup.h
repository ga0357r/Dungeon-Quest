// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Engine.h>
#include "Kismet/GameplayStatics.h"
#include "MyFirstPersonCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinPickup.generated.h"

UCLASS()
class CW_API ACoinPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//The gun pickup trigger
	UPROPERTY(EditAnywhere)
	ATriggerVolume* coinPickupTrigger;

	//The player that can pickup this gun
	UPROPERTY(EditAnywhere)
	AActor* player;

	//player should pickup the gun
	UFUNCTION(BlueprintCallable, Category = "Disable")
	void PickupCoin();

};
