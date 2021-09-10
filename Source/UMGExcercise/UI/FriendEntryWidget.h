// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "FriendEntryWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class UMGEXCERCISE_API UFriendEntryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Name;
};
