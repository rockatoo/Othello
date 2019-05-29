// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "OthelloBlock.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OthelloBlockGrid.generated.h"

/** Class used to spawn blocks and manage score */
UCLASS(minimalapi)
class AOthelloBlockGrid : public AActor
{
	GENERATED_BODY()

		/** Dummy root component */
		UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* DummyRoot;

	/** Text component for the score */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UTextRenderComponent* TurnText;

public:
	AOthelloBlockGrid();

	/** How many blocks have been clicked */
	int32 Score;

	/** Number of blocks along each side of grid */
	UPROPERTY(Category = Grid, EditAnywhere, BlueprintReadOnly)
		int32 Size;

	/** Spacing of blocks */
	UPROPERTY(Category = Grid, EditAnywhere, BlueprintReadOnly)
		float BlockSpacing;

	/** Activated after 'AOthelloBlock::PutStone()' activates */
	void AfterPutStone();

protected:
	// Begin AActor interface
	virtual void BeginPlay() override;
	// End AActor interface

	UPROPERTY(BlueprintReadOnly)
		TArray<AOthelloBlock*> BlockArray;

public:
	/** Check stone can be put on (start_x, start_y)
	* @return true stone can be put on this position
	* @return false stone can't be put on this position
	*/
	UFUNCTION(BlueprintCallable, Category = "Check")
		bool CheckPossibility(uint8 start_x, uint8 start_y);

	/** Change color of stones which lie on 8-directions */
	void ChangeStonesColor(uint8 stone_x, uint8 stone_y);

	/** Check whether game is over or not
	* @return true game is over
	* @return false game is not over
	*/
	bool CheckGameOver();

	/** Get block on (x, y) */
	UFUNCTION(BlueprintCallable, Category = "Block")
		AOthelloBlock* GetBlock(uint8 x, uint8 y);

	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }
	/** Returns ScoreText subobject **/
	FORCEINLINE class UTextRenderComponent* GetTurnText() const { return TurnText; }
};