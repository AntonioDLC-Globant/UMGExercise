// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendsContainerWidget.h"

#include "UMGExcercise/FriendProfile.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "UMGExcercise/UMGExerciseGameInstance.h"

void UFriendsContainerWidget::RemoveFriendEntryWidget(UVerticalBox* VBox, FString Name)
{
	for (auto Child : VBox->GetAllChildren())
	{
		UFriendEntryWidget* FriendEntry = (UFriendEntryWidget*)Child;
		if (FriendEntry->Name->GetText().ToString() == Name)
		{
			VBox->RemoveChild(Child);
		}
	}
}

void UFriendsContainerWidget::MoveFriendEntryWidget(UVerticalBox* From, UVerticalBox* To, FString Name)
{
	UFriendEntryWidget* FriendEntry = CreateWidget<UFriendEntryWidget>(this, FriendEntryWidgetClass);
	if (FriendEntry)
	{
		To->AddChild(FriendEntry);
		RemoveFriendEntryWidget(From, Name);
		FriendEntry->Name->SetText(FText::FromString(Name));
	}
}

void UFriendsContainerWidget::FriendConnected(const FString& Name)
{
	MoveFriendEntryWidget(OfflineFriendList, OnlineFriendList, Name);
}

void UFriendsContainerWidget::FriendDisconnected(const FString& Name)
{
	MoveFriendEntryWidget(OnlineFriendList, OfflineFriendList, Name);
}

void UFriendsContainerWidget::ToogleListWidget(UVerticalBox* Widget)
{
	Widget->IsVisible() ? FoldListWidget(Widget) : UnfoldListWidget(Widget);
}

void UFriendsContainerWidget::ToogleOnlineFriendsListWidget() { ToogleListWidget(OnlineFriendList); }
void UFriendsContainerWidget::ToogleOfflineFriendsListWidget() { ToogleListWidget(OfflineFriendList); }

void UFriendsContainerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	UFriendsManager* FriendsManager = GetGameInstance<UUMGExerciseGameInstance>()->FriendsManager;
	for (auto FriendProfile : FriendsManager->AllFriends)
	{
		FriendProfile.Connected ? FriendConnected(FriendProfile.Name) : FriendDisconnected(FriendProfile.Name);
	}

	FriendsManager->OnFriendConnectedDelegate.AddDynamic(this, &UFriendsContainerWidget::FriendConnected);
	FriendsManager->OnFriendDisconnectedDelegate.AddDynamic(this, &UFriendsContainerWidget::FriendDisconnected);

	OnlineListCollapser->OnClicked.AddDynamic(this, &UFriendsContainerWidget::ToogleOnlineFriendsListWidget);
	OfflineListCollapser->OnClicked.AddDynamic(this, &UFriendsContainerWidget::ToogleOfflineFriendsListWidget);
}
