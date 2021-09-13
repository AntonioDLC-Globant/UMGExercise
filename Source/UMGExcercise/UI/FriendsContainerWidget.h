// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataTable.h" 
#include "UMGExcercise/FriendsManager.h"

#include "FriendsContainerWidget.generated.h"

class UFriendListWidget;
class UVerticalBox;
class UButton;
/**
 * 
 */
UCLASS()
class UMGEXCERCISE_API UFriendsContainerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	UFriendListWidget* OnlineFriendList;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	UFriendListWidget* OfflineFriendList;

	void NativeOnInitialized() override;

	UFUNCTION()
	void FriendConnected(const FString& Name);

	UFUNCTION()
	void FriendDisconnected(const FString& Name);

private:
	void MoveFriendEntryWidget(UFriendListWidget* From, UFriendListWidget* To, FString Name);
};
