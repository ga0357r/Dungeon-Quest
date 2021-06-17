// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Gun.h"

// Sets default values for this component's properties
UFPS_Gun::UFPS_Gun()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	PrimaryComponentTick.SetTickFunctionEnable(true);
}


// Called when the game starts
void UFPS_Gun::BeginPlay()
{
	Super::BeginPlay();

	// ...

	

	// find the weapon
	//weapon = GetOwner();

	//get all components of the player
	GetWorld()->GetFirstPlayerController()->GetPawn()->GetComponents<UActorComponent>(components_of_player);

	for (int i = 0; i < components_of_player.Num(); i++)
	{
		UActorComponent* component = components_of_player[i];
		FString name = component->GetName();
		//if the name is weapon
		if (name == "Weapon")
		{
			//this is the  actor/object that should be stored
			weapon = component;
		}
		
	}

	
	
	
	//turn this weapon off
	//disable its collision
	/*GetOwner()->SetActorEnableCollision(false);*/
	

	//disable it from ticking
	//GetOwner()->SetActorTickEnabled(false);
	weapon->SetComponentTickEnabled(false);
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.SetTickFunctionEnable(false);
	

	//hide it in the game
	//deactivate the scene component
	weapon->Deactivate();
	//turn the weapon off
	weapon->SetActive(false);
	
	
}


// Called every frame
void UFPS_Gun::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	//UMyGun_ActorComponent object = GetObjectByNa
	//value = UMyGun_ActorComponent::GetValueOf_HasBeenPicked();

	////if the player has collided with the gun
	//if (UMyGun_ActorComponent::GetValueOf_HasBeenPicked() == true)
	//{
	//	//turn this weapon on
	//	//enable its collision
	//	


	//	//disable the  ticking
	//	weapon->SetComponentTickEnabled(true);
	//	PrimaryComponentTick.bCanEverTick = true;
	//	PrimaryComponentTick.SetTickFunctionEnable(true);


	//	//show it in the game
	//	//activate the scene component
	//	weapon->Activate();
	//	//turn the weapon on
	//	weapon->SetActive(true);
	//}

	//turn this weapon on
		//enable its collision

	//need access to another UActorComonent
	
	

		//disable the  ticking
	weapon->SetComponentTickEnabled(true);
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.SetTickFunctionEnable(true);


	//show it in the game
	//activate the scene component
	weapon->Activate();
	//turn the weapon on
	weapon->SetActive(true);
}

