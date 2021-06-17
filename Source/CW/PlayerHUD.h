// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "Kismet/GameplayStatics.h"
#include "MyFirstPersonCharacter.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"


//the NPC message to the player
struct NPCMessage
{
	//the message itself
	FString message;

	//the time to displ;ay this message
	float time;

	//the color of the message
	FColor color;

	//set the default values
	NPCMessage()
	{
		time = 1.f;

		color = FColor::White;
	}

	//called when sending a message to the player
	NPCMessage(FString _message, float _time, FColor _color)
	{
		message = _message;

		time = _time;

		color = _color;
	}
};



/**
 * 
 */
UCLASS()
class CW_API APlayerHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	// The font used to render the text in the HUD.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
	UFont* hudFont;
	
	// The Text to be displayed in the HUD
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
	FString npcTextToPlayer;



	// The array of messages available
	TArray<NPCMessage> messages;

	// method to add a message to display
	void addMessage(NPCMessage msg); 

	//override default drawHud method
	virtual void DrawHUD() override;

	void WriteMessages();

	void DrawHealthBar();
	


};
