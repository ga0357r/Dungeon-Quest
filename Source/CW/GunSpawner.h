// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Engine.h>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Manager.h>
#include "GunSpawner.generated.h"


UCLASS()
class CW_API AGunSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	//testing macros
	UPROPERTY(VisibleAnywhere)
	float test = 90.f;

	//The Manager object
	UPROPERTY(EditAnywhere)
	AManager* manager;
	
	//The gun reference object 
	UPROPERTY(EditAnywhere)
	UActorComponent* gunReference;

	

};
