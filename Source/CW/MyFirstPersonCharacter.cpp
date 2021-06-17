// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstPersonCharacter.h"

// Sets default values
AMyFirstPersonCharacter::AMyFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	//Bind the ForwardOrBackward axis defined in the input settings to the moveforwardorbackward method
	PlayerInputComponent->BindAxis("ForwardOrBackward", this, &AMyFirstPersonCharacter::MoveForwardOrBackward);

	//Bind theLeftOrRight axis defined in the input settings to the MoveLeftOrRight method
	PlayerInputComponent->BindAxis("LeftOrRight", this, &AMyFirstPersonCharacter::MoveLeftOrRight);

	//Bind Yaw axis defined in the input settings to the Yaw method
	PlayerInputComponent->BindAxis("Yaw", this, &AMyFirstPersonCharacter::Yaw);

	//Bind Pitch axis defined in the input settings to the Pitch method
	PlayerInputComponent->BindAxis("Pitch", this, &AMyFirstPersonCharacter::Pitch);
}

//definition for forward and backward movement
void AMyFirstPersonCharacter::MoveForwardOrBackward(float amount)
{
	//if controller has been setup and amount is greater than or less than 0
	if (Controller && amount != 0)
	{
		//get the forward vector of this actor
		FVector forward_or_backward_movement = GetActorForwardVector();

		//move the player forward by this amount
		AddMovementInput(forward_or_backward_movement, amount);
	}
}

//definition for left and right movement
void AMyFirstPersonCharacter::MoveLeftOrRight(float amount)
{
	//if controller has been setup and amount is greater than or less than 0
	if (Controller && amount != 0)
	{
		//get the right vector of this actor
		FVector left_or_right_movement = GetActorRightVector();

		//move the player right by this amount
		AddMovementInput(left_or_right_movement, amount);
	}
}

//definition for horizontal Camera movement
void AMyFirstPersonCharacter::Yaw(float amount)
{
	//add a yaw input to the x camera axis
	AddControllerYawInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}

//definition for horizontal Camera movement
void AMyFirstPersonCharacter::Pitch(float amount)
{
	//add a yaw input to the x camera axis
	AddControllerPitchInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}
