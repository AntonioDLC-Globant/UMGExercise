// Fill out your copyright notice in the Description page of Project Settings.

#include "UMGExerciseLevelScriptActor.h"

#include "UI/FriendsContainerWidget.h"
#include "UI/FriendConnectionChangedWidget.h"

void AUMGExerciseLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	UFriendsContainerWidget* FriendsContainerWidget = CreateWidget<UFriendsContainerWidget>(GetWorld(), FriendsContainerWidgetClass);
	if (FriendsContainerWidget)
	{
		FriendsContainerWidget->AddToViewport();
	}
	//else warning

	UFriendConnectionChangedWidget* ToastWidget = CreateWidget<UFriendConnectionChangedWidget>(GetWorld(), FriendConnectionChangedWidgetClass);
	if (ToastWidget)
	{
		ToastWidget->AddToViewport();
	}
	//else warning
}
