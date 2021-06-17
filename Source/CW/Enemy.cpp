// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"






// Sets default values
AEnemy::AEnemy(const FObjectInitializer& PCIP):Super(PCIP)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	speed = 40;
	hitPoints = 10;
	experience = 1;
	droppedLoot = NULL;
	attackTimeout = 0.75f;
	timeSinceLastStrike = 0;
	sight = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("sight"));
	sight->SetupAttachment(RootComponent);
	attackRange = PCIP.CreateDefaultSubobject<USphereComponent>(this,TEXT("attackRange"));
	attackRange->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// move the enemy towards the player

	//return the player object
	AMyFirstPersonCharacter* player = Cast<AMyFirstPersonCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	//if player is null break out of this method
	if (!player) return;

	//if player is  not null
	//get the player position
	FVector playerPos = player->GetActorLocation();

	//get the vector needed to move towards the player
	FVector toPlayer = playerPos - GetActorLocation();

	//the distance to the player
	float distanceToPlayer = toPlayer.Size();

	//if the distance to player is grerater than the sight radius break out of this method
	if (distanceToPlayer > sight->GetScaledSphereRadius())
	{
		return;
	}

	//normalize the vector
	toPlayer /= distanceToPlayer;

	//move towards the player
	AddMovementInput(toPlayer, speed * DeltaTime);


	// Enemy face the target

	// look in the player's direction 
	FRotator toPlayerRotation = toPlayer.Rotation();

	//look straight ahead
	toPlayerRotation.Pitch = 0; 

	//set the rotation of the Enemy
	RootComponent->SetWorldRotation(toPlayerRotation);

	
	

	
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


bool AEnemy::PlayerIsInSightRange(float s_range)
{
	return s_range < sight->GetScaledSphereRadius();
}


bool AEnemy::PlayerIsInAttackRange(float a_range)
{
	return a_range < attackRange->GetScaledSphereRadius();
}
