// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "MyGun_ActorComponent.h"
#include "FPS_Gun.generated.h"





UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CW_API UFPS_Gun : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFPS_Gun();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
private:

	//The weapon attached to this character
	UPROPERTY(EditAnywhere)
	bool value;

	//The weapon attached to this character
	UPROPERTY(EditAnywhere)
	UActorComponent* weapon;
	
	//The Components of the Player 
	UPROPERTY(EditAnywhere)
	TArray<UActorComponent*> components_of_player;

	
};
