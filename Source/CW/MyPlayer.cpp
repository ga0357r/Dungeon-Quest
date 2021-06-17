// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include <UMG.h>

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	
	 
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);

	//get the location of the player
	playerLocation = GetTransform().GetLocation();

	//get the rotation of the player
	playerRotation = GetTransform().GetRotation();

	/*UE_LOG(LogTemp, Warning, TEXT("Location: %s"), *playerLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Rotation: %s"), *playerRotation.Vector().ToString());*/

	DrawLine();
	
	
}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	check(PlayerInputComponent);

	//Bind the ForwardOrBackward axis defined in the input settings to the moveforwardorbackward method
	PlayerInputComponent->BindAxis("ForwardOrBackward", this, &AMyPlayer::MoveForwardOrBackward);
	
	//Bind theLeftOrRight axis defined in the input settings to the MoveLeftOrRight method
	PlayerInputComponent->BindAxis("LeftOrRight", this, &AMyPlayer::MoveLeftOrRight);

	//Bind Yaw axis defined in the input settings to the Yaw method
	PlayerInputComponent->BindAxis("Yaw", this, &AMyPlayer::Yaw);

	//Bind Pitch axis defined in the input settings to the Pitch method
	PlayerInputComponent->BindAxis("Pitch", this, &AMyPlayer::Pitch);

}

//definition for forward and backward movement
void AMyPlayer::MoveForwardOrBackward(float amount)
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
void AMyPlayer::MoveLeftOrRight(float amount)
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
void AMyPlayer::Yaw(float amount)
{
	//add a yaw input to the x camera axis
	AddControllerYawInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}

//definition for horizontal Camera movement
void AMyPlayer::Pitch(float amount)
{
	//add a yaw input to the x camera axis
	AddControllerPitchInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}

//Draw DebugLine
void AMyPlayer::DrawLine()
{
	//the start position and end position of the line
	FVector start_position, end_position;


	start_position = playerLocation + FVector(0.f, 0.f, 50.f);

	end_position = playerLocation + playerRotation.Vector() * reach;

	//draw a red line in the world
	DrawDebugLine(
		GetWorld(), 
		start_position, 
		end_position,
		FColor(255, 0, 0), 
		false, 
		0.f, 
		0.f,
		5.f
	);
}
