// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FriendListWidget.generated.h"

/**
 * 
 */
UCLASS()
class UMGEXCERCISE_API UFriendListWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	class UVerticalBox* ListWidget;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	class UButton* ListCollapser;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UTextBlock* StatusName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFriendEntryWidget> FriendEntryWidgetClass;

	UPROPERTY()
	bool bIsFolded = false;

	void NativeOnInitialized() override;

	UFUNCTION(BlueprintCallable)
	void SetName(const FString& name);

	UFUNCTION()
	void AddFriend(const FString& Name);

	UFUNCTION()
	void RemoveFriend(const FString& Name);

	UFUNCTION(BlueprintImplementableEvent)
	void FoldListWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void UnfoldListWidget();


private:
	UFUNCTION()
	void ToogleListWidget();
};
