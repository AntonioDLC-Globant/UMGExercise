// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "FriendConnectionChangedWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class UMGEXCERCISE_API UFriendConnectionChangedWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Message;

	UFUNCTION(BlueprintNativeEvent)
	void FriendConnected(const FString& Name);
	UFUNCTION(BlueprintCallable)
	virtual void FriendConnected_Implementation(const FString& Name);


	UFUNCTION(BlueprintNativeEvent)
	void FriendDisconnected(const FString& Name);
	UFUNCTION(BlueprintCallable)
	virtual void FriendDisconnected_Implementation(const FString& Name);

	void NativeOnInitialized() override;
};
