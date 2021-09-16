// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendsViewModel.h"

#include "UMGExcercise/FriendsManager.h"

void UFriendsViewModel::Initialize(UFriendsManager* NewFriendsManager)
{
	FriendsManager = NewFriendsManager;
	FriendsManager->OnFriendConnectedDelegate.AddDynamic(this, &UFriendsViewModel::FriendConnected);
	FriendsManager->OnFriendDisconnectedDelegate.AddDynamic(this, &UFriendsViewModel::FriendDisconnected);
}

void UFriendsViewModel::FriendConnected(const FString& Name) { OnFriendConnectedDelegate.Broadcast(Name); }

void UFriendsViewModel::FriendDisconnected(const FString& Name) { OnFriendDisconnectedDelegate.Broadcast(Name); }

TArray<FFriendProfileStruct>& UFriendsViewModel::GetAllFriends() const { return FriendsManager->AllFriends; }
