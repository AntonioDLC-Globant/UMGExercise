// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FriendInfoTooltip.generated.h"

/**
 * 
 */
UCLASS()
class UMGEXCERCISE_API UFriendInfoTooltip : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Username;

	UPROPERTY(BlueprintReadWrite)
	FVector2D Offset = { 15, 15 };

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION()
	void UpdatePosition();
};
