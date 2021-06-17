// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Engine.h>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Manager.generated.h"

UCLASS()
class CW_API AManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//testing macros
	UPROPERTY(VisibleAnywhere)
	float test = 90.f;

	//the gun that will be picked up by player
	UPROPERTY(EditAnywhere)
	AActor* gunModelBlueprint;

	//The gun pickup trigger
	UPROPERTY(EditAnywhere)
	ATriggerVolume* gunPickupTrigger;

	//The player that can pickup this gun
	UPROPERTY(EditAnywhere)
	AActor* player;

	//Has Player picked up the gun 
	UPROPERTY(EditAnywhere)
	bool gunBlueprintModelHasBeenPicked;

	//player should pickup the gun
	UFUNCTION(BlueprintCallable, Category = "Disable")
	void PickupGun();

};
