// Fill out your copyright notice in the Description page of Project Settings.


#include "UMGExerciseGameInstance.h"

#include "FriendsManager.h"

void UUMGExerciseGameInstance::Init()
{
	Super::Init();
	
	FriendsManager = NewObject<UFriendsManager>(this, FriendsManagerClass);
	FriendsManager->Initialize();
}