// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OthelloGameMode.generated.h"

UENUM()
enum class ETurn
{
	Black,
	White
};

/** GameMode class to specify pawn and playercontroller */
UCLASS(minimalapi)
class AOthelloGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AOthelloGameMode();

	/** Who's turn? */
	ETurn GameTurn;
};



