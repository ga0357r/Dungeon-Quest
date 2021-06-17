// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"

void APlayerHUD::DrawHUD()
{
	//main draw loop for the HUD
	Super::DrawHUD();
	
	addMessage(NPCMessage("", 5.0f, FColor::White));
	
	WriteMessages();

	//DrawLine(200, 300, 400, 500, FLinearColor::Blue);

	////or some text in the middle of the screen
	//float ScreenX = 0.f;
	//float ScreenY = 0.f;
	//float TextScale = 1.5f;
	//bool bDontScale = false;
	//DrawText(npcTextToPlayer, FColor::White, ScreenX, ScreenY, hudFont, TextScale, bDontScale);
}


void APlayerHUD::addMessage(NPCMessage msg)
{
	messages.Add(msg);
}

void APlayerHUD::WriteMessages()
{
	// iterate from back to front thru the list, so if we remove
 // an item while iterating, there won't be any problems
	for (int c = messages.Num() - 1; c >= 0; c--)
	{
		// draw the background box the right size for the message
		float ow, oh, pad = 10.f;
		GetTextSize(messages[c].message, ow, oh, hudFont, 1.f);
		float messageH = oh + 2 * pad;
		float x = 0, y = c * messageH;
		DrawRect(FLinearColor::Black, x, y, /*Canvas->SizeX*/ .1f, messageH);
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);
		// reduce lifetime by the time that passed since last frame.
		messages[c].time -= GetWorld()->GetDeltaSeconds();
		// if the message's time is up, remove it
		if (messages[c].time < 0)
		{
			messages.RemoveAt(c);
		}
	}
}

//Draw Player HealthBar
void APlayerHUD::DrawHealthBar()
{
	// Draw the Player healthbar.
	AMyFirstPersonCharacter* player = Cast<AMyFirstPersonCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	float barWidth = 10.f, barHeight = 2.f, barPad = .2f, barMargin = 2.f;
	float percHp = player->Hp / player->MaxHp;
	DrawRect(FLinearColor::Blue, Canvas->SizeX - barWidth - barPad - barMargin, Canvas->SizeY - barHeight - barPad - barMargin, barWidth + 2 * barPad, barHeight + 2 * barPad);
	DrawRect(FLinearColor(1 - percHp, percHp, 0, 1),Canvas->SizeX - barWidth - barMargin, Canvas->SizeY - barHeight - barMargin, barWidth * percHp, barHeight);
}
