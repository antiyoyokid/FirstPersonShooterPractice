// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Attempt1GameMode.h"
#include "Attempt1HUD.h"
#include "Attempt1Character.h"
#include "UObject/ConstructorHelpers.h"

AAttempt1GameMode::AAttempt1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAttempt1HUD::StaticClass();
}
