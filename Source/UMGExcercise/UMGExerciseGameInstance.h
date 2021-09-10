// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FriendsManager.h"

#include "UMGExerciseGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UMGEXCERCISE_API UUMGExerciseGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void Init() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UFriendsManager> FriendsManagerClass;

	UPROPERTY(BlueprintReadOnly)
	UFriendsManager* FriendsManager;
	
};
