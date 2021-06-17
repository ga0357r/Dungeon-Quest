// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "MyFirstPersonCharacter.h"
#include "NPC.generated.h"

UCLASS()
class CW_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC(const FObjectInitializer& PCIP);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//sphere gizmo, when the player is in the sphere do something
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
	USphereComponent* range;

	// NPC's message to the player 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	FString npcMessage;

	//what should happen ifhe player is in proximity
	UFUNCTION(BlueprintNativeEvent, Category = Collision)
	void PlayerInProximity(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult);
};
