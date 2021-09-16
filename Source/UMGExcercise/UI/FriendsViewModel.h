// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UMGExcercise/FriendProfile.h"
#include "FriendsViewModel.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFriendConnectedViewModel, const FString&, FriendName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFriendDisconnectedViewModel, const FString&, FriendName);

UCLASS(Blueprintable, BlueprintType)
class UMGEXCERCISE_API UFriendsViewModel : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnFriendConnectedViewModel OnFriendConnectedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnFriendDisconnectedViewModel OnFriendDisconnectedDelegate;

	UPROPERTY()
	class UFriendsManager* FriendsManager;

	UFUNCTION()
	void Initialize(class UFriendsManager* NewFriendsManager);

	UFUNCTION()
	void FriendConnected(const FString& Name);

	UFUNCTION()
	void FriendDisconnected(const FString& Name);

	UFUNCTION()
	TArray<FFriendProfileStruct>& GetAllFriends() const;
};
