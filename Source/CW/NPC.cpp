// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"

// Sets default values
ANPC::ANPC(const FObjectInitializer& PCIP):Super(PCIP)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create the sphere object
	range = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("Range"));
	// attach the sphere to the NPC
	range->SetupAttachment(RootComponent);
	//set the radius of thge sphere
	range->SetSphereRadius(32.f);
	// Code to make ANPC::PlayerInProximity() run when this proximity sphere overlaps another actor.
	range->OnComponentBeginOverlap.AddDynamic(this, &ANPC::PlayerInProximity);
	
	npcMessage = "Hello Joe, I'm Gabriel, you have to pick up all pickable items in this level without dying, Good Luck."; 
	
}

void ANPC::PlayerInProximity_Implementation(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//
	npcMessage = "works";
	//this is where the code on “what to do when a collision is detected” goes.
	// if the overlapped actor is the player, display my message
	
	//find the player
	AMyFirstPersonCharacter* player = Cast<AMyFirstPersonCharacter>(OtherActor);

	//if there is no player break out of this method
	if (player == nullptr)
	{
		// The intersected actor wasn't the player, so ignore this overlap
		return;
	}

	// The player object has multiple components. we don't want an overlap event
	// for EACH component, so just check for intersection with player's root component.

	//if this component is not the player's root component break out of this method
	if (OtherComp != player->GetRootComponent())
	{
		return;
	}
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	APlayerHUD* hud = Cast<APlayerHUD>(PController->GetHUD());
	hud->addMessage(NPCMessage(npcMessage, 5.f, FColor::White));

}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//return the player object
	AMyFirstPersonCharacter* player = Cast<AMyFirstPersonCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	//if player is null break out of this method
	if (!player)
	{
		npcMessage = "";
		return;
	}

	npcMessage = "Hello Joe, I'm Gabriel, you have to pick up all pickable items in this level without dying, Good Luck.";
	//if player is  not null
	//get the player position
	FVector playerPos = player->GetActorLocation();

	//needed to get the distance to the player
	FVector toPlayer = playerPos - GetActorLocation();

	//the distance to the player
	float distanceToPlayer = toPlayer.Size();

	//if the distance to player is grerater than the sight radius break out of this method
	if (distanceToPlayer > range->GetScaledSphereRadius())
	{
		npcMessage = "";
		return;
	}
	
	//if close enough to the NPC

	//display text to player
	APlayerController* samePlayer = GetWorld()->GetFirstPlayerController();
	APlayerHUD* hud = Cast<APlayerHUD>(samePlayer->GetHUD());
	hud->addMessage(NPCMessage(npcMessage, 5.f, FColor::Black));
}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

