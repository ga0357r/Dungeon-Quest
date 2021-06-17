// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Engine.h>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Model_Gun.generated.h"

UCLASS()
class CW_API AModel_Gun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AModel_Gun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
