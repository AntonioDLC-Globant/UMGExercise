// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendConnectionChangedWidget.h"

#include "UMGExcercise/UMGExerciseGameInstance.h"
#include "UMGExcercise/FriendsManager.h"
#include "Components/TextBlock.h"

void UFriendConnectionChangedWidget::FriendConnected_Implementation(const FString& Name)
{
	Message->SetText(FText::FromString(Name + TEXT(" connected")));
}

void UFriendConnectionChangedWidget::FriendDisconnected_Implementation(const FString& Name)
{
	Message->SetText(FText::FromString(Name + TEXT(" disconnected")));
}

void UFriendConnectionChangedWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	UFriendsManager* FriendsManager = GetGameInstance<UUMGExerciseGameInstance>()->FriendsManager;
	FriendsManager->OnFriendConnectedDelegate.AddDynamic(this, &UFriendConnectionChangedWidget::FriendConnected);
	FriendsManager->OnFriendDisconnectedDelegate.AddDynamic(this, &UFriendConnectionChangedWidget::FriendDisconnected);
}