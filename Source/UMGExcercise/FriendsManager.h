// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h" 
#include "FriendProfile.h"

#include "FriendsManager.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFriendConnected, const FString&, FriendName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFriendDisconnected, const FString&, FriendName);

UCLASS(BlueprintType, Blueprintable)
class UMGEXCERCISE_API UFriendsManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDataTable* FriendsData;

	UPROPERTY(BlueprintAssignable)
	FOnFriendConnected OnFriendConnectedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnFriendDisconnected OnFriendDisconnectedDelegate;

	UPROPERTY()
	TArray<FFriendProfileStruct> AllFriends;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UFriendsViewModel* FriendsViewModel;

	UFUNCTION()
	void Initialize();

	UFUNCTION()
	void ToogleRandomFriendStatus();
};