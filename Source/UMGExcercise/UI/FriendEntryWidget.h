// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "FriendEntryWidget.generated.h"

class UFriendInfoTooltip;
/**
 * 
 */
UCLASS()
class UMGEXCERCISE_API UFriendEntryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	class UTextBlock* Name;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	class UButton* HoverArea;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UFriendInfoTooltip> FriendInfoTooltipClass;

	UPROPERTY()
	UFriendInfoTooltip* Tooltip;

	UPROPERTY()
	FVector2D TooltipOffset;

	UFUNCTION()
	void NativeOnInitialized() override;

	UFUNCTION()
	void OnHovered();
	
	UFUNCTION()
	void OnUnhovered();
};
