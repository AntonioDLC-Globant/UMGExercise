// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendsContainerWidget.h"

#include "FriendListWidget.h"
#include "UMGExcercise/FriendProfile.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "UMGExcercise/UMGExerciseGameInstance.h"

void UFriendsContainerWidget::MoveFriendEntryWidget(UFriendListWidget* From, UFriendListWidget* To, FString Name)
{
	From->RemoveFriend(Name);
	To->AddFriend(Name);
}

void UFriendsContainerWidget::FriendConnected(const FString& Name){	MoveFriendEntryWidget(OfflineFriendList, OnlineFriendList, Name); }
void UFriendsContainerWidget::FriendDisconnected(const FString& Name){ MoveFriendEntryWidget(OnlineFriendList, OfflineFriendList, Name); }

void UFriendsContainerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	UFriendsManager* FriendsManager = GetGameInstance<UUMGExerciseGameInstance>()->FriendsManager;
	for (auto FriendProfile : FriendsManager->AllFriends)
	{
		FriendProfile.Connected ? FriendConnected(FriendProfile.Name) : FriendDisconnected(FriendProfile.Name);
	}

	FriendsManager->OnFriendConnectedDelegate.AddDynamic(this, &UFriendsContainerWidget::FriendConnected);
	FriendsManager->OnFriendDisconnectedDelegate.AddDynamic(this, &UFriendsContainerWidget::FriendDisconnected);
}
