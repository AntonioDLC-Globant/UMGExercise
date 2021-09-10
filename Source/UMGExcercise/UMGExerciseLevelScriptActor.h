// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"

#include "UMGExerciseLevelScriptActor.generated.h"


/**
 * 
 */
UCLASS()
class UMGEXCERCISE_API AUMGExerciseLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf< class UFriendsContainerWidget > FriendsContainerWidgetClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf< class UFriendConnectionChangedWidget > FriendConnectionChangedWidgetClass;

	void BeginPlay() override;
};
