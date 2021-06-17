// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Engine.h>

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyGun_ActorComponent.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CW_API UMyGun_ActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyGun_ActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//get the value of HasBeenPicked 
	 bool GetValueOf_HasBeenPicked();


private:
	//testing macros
	UPROPERTY(VisibleAnywhere)
	float test = 90.f;

	//The gun pickup trigger
	UPROPERTY(EditAnywhere)
	ATriggerVolume* gunPickupTrigger;
	
	//The player that can pickup this gun
	UPROPERTY(EditAnywhere)
	AActor* player;

	//Has Player picked up the gun 
	UPROPERTY(EditAnywhere)
	bool HasBeenPicked;

	//player should pickup the gun
	UFUNCTION(BlueprintCallable, Category = "Disable")
	void PickupGun();
};
