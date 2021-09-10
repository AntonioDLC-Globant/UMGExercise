// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendsManager.h"

void UFriendsManager::Initialize()
{
	UWorld* World = GetWorld();

	if (World && FriendsData)
	{
		TMap<FName, uint8*> FriendsDataRows = FriendsData->GetRowMap();
		for (const auto& FriendsDataRow : FriendsDataRows)
		{
			FFriendProfileStruct* FriendProfileStruct = reinterpret_cast<FFriendProfileStruct*>(FriendsDataRow.Value);
			if (FriendProfileStruct == nullptr)
			{
				continue;
			}
			AllFriends.Add(*FriendProfileStruct);

			FriendProfileStruct->Connected ? OnFriendConnectedDelegate.Broadcast(FriendProfileStruct->Name) : OnFriendDisconnectedDelegate.Broadcast(FriendProfileStruct->Name);
		}

		FTimerHandle MyTimer;
		World->GetTimerManager().SetTimer(MyTimer, this, &UFriendsManager::ToogleRandomFriendStatus, 3.0f, true/*InbLoop*/);
	}

	OnFriendConnectedDelegate.AddDynamic(this, &UFriendsManager::OnFriendConnectedEvent);
}

void UFriendsManager::ToogleRandomFriendStatus()
{
	int i = FMath::FRandRange(0, AllFriends.Num() - 1);
	AllFriends[i].Connected = !AllFriends[i].Connected;
	AllFriends[i].Connected ? OnFriendConnectedDelegate.Broadcast(AllFriends[i].Name) : OnFriendDisconnectedDelegate.Broadcast(AllFriends[i].Name);
}