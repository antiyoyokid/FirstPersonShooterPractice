// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "Attempt1HUD.generated.h"

UCLASS()
class AAttempt1HUD : public AHUD
{
	GENERATED_BODY()

public:
	AAttempt1HUD();

	// Primary draw call for the HUD 
	virtual void DrawHUD() override;

private:
	// Crosshair asset pointer 
	class UTexture2D* CrosshairTex;
};

