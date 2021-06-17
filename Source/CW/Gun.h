// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <MyFirstPersonCharacter.h>
#include "Gun.generated.h"

UCLASS()
class CW_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//turn this object off
	void TurnObjectOff();

private:
	//testing macros
	UPROPERTY(VisibleAnywhere)
	float test = 90.f;

	//The Manager object
	UPROPERTY(EditAnywhere)
	AMyFirstPersonCharacter* player;

};
