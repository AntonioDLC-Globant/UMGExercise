// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendsContainerWidget.h"

#include "FriendListWidget.h"
#include "UMGExcercise/FriendProfile.h"
#include "Components/TextBlock.h"
#include "FriendsViewModel.h"
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

	for (auto FriendProfile : FriendsViewModel->GetAllFriends())
	{
		FriendProfile.Connected ? FriendConnected(FriendProfile.Name) : FriendDisconnected(FriendProfile.Name);
	}

	FriendsViewModel->OnFriendConnectedDelegate.AddDynamic(this, &UFriendsContainerWidget::FriendConnected);
	FriendsViewModel->OnFriendDisconnectedDelegate.AddDynamic(this, &UFriendsContainerWidget::FriendDisconnected);
}

void UFriendsContainerWidget::NativeDestruct()
{
	FriendsViewModel->OnFriendConnectedDelegate.RemoveDynamic(this, &UFriendsContainerWidget::FriendConnected);
	FriendsViewModel->OnFriendDisconnectedDelegate.RemoveDynamic(this, &UFriendsContainerWidget::FriendDisconnected);
}
