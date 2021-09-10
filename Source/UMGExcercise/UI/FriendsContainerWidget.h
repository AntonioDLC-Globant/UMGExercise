// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataTable.h" 
#include "FriendEntryWidget.h"
#include "UMGExcercise/FriendsManager.h"

#include "FriendsContainerWidget.generated.h"

class VerticalBox;
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
		UVerticalBox* OnlineFriendList;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
		UButton* OnlineListCollapser;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
		UVerticalBox* OfflineFriendList;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
		UButton* OfflineListCollapser;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UFriendEntryWidget> FriendEntryWidgetClass;

	void NativeOnInitialized() override;

	UFUNCTION()
	void FriendConnected(const FString& Name);

	UFUNCTION()
	void FriendDisconnected(const FString& Name);

	UFUNCTION(BlueprintImplementableEvent)
	void FoldListWidget(UVerticalBox* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void UnfoldListWidget(UVerticalBox* Widget);


private:
	UFUNCTION()
	void ToogleOnlineFriendsListWidget();

	UFUNCTION()
	void ToogleOfflineFriendsListWidget();

	void ToogleListWidget(UVerticalBox* Widget);
	void RemoveFriendEntryWidget(UVerticalBox* VBox, FString Name);
	void MoveFriendEntryWidget(UVerticalBox* From, UVerticalBox* To, FString Name);
};
