// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class CW_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//How far ahead we can reach
	float reach = 100.f;

	//The Player Location
	FVector playerLocation;
	
	//The Player Rotation
	FQuat playerRotation;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//move the player forward or backward
	void MoveForwardOrBackward(float amount);

	//move the player left or right
	void MoveLeftOrRight(float amount);

	//move the camera left or right
	void Yaw(float amount);
	
	//move the camera up or down
	void Pitch(float amount);

	//draw a debug line
	void DrawLine();

};
