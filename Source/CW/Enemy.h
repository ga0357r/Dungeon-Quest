// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include <MyFirstPersonCharacter.h>
#include "Components/SphereComponent.h"
#include "Enemy.generated.h"

UCLASS()
class CW_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy(const FObjectInitializer& PCIP);

	//check  if the player is in attack range
	bool PlayerIsInAttackRange(float a_range);


	//check if player is in sight range
	bool PlayerIsInSightRange(float s_range);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// The speed of this enemy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EnemyProperties)
	float speed;

	// The hitpoints of this enemy 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EnemyProperties)
	float hitPoints;

	// Player Experience gained from defeating this enemy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EnemyProperties)
	int experience;

	// The type of item dropped by the enemy when defeated
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EnemyProperties)
	UClass* droppedLoot;

	// The amount of damage this enemy does to the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EnemyProperties)
	float baseAttackDamage;

	// Amount of time the monster needs to rest before attacking the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EnemyProperties)
	float attackTimeout;

	// Time since monster's last strike
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = EnemyProperties)
	float timeSinceLastStrike;

	// Range for the enemy sight
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
	USphereComponent* sight;

	// Range for enemy's attack
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
	USphereComponent* attackRange;

};
