// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendListWidget.h"

#include "FriendEntryWidget.h"
#include "UMGExcercise/FriendProfile.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "UMGExcercise/UMGExerciseGameInstance.h"

void UFriendListWidget::RemoveFriend(const FString& Name)
{
	for (auto Child : ListWidget->GetAllChildren())
	{
		UFriendEntryWidget* FriendEntry = (UFriendEntryWidget*)Child;
		if (FriendEntry->Name->GetText().ToString() == Name)
		{
			ListWidget->RemoveChild(Child);
		}
	}
}

void UFriendListWidget::AddFriend(const FString& Name)
{
	UFriendEntryWidget* FriendEntry = CreateWidget<UFriendEntryWidget>(this, FriendEntryWidgetClass);
	if (FriendEntry)
	{
		ListWidget->AddChild(FriendEntry);
		FriendEntry->Name->SetText(FText::FromString(Name));
	}
}

void UFriendListWidget::ToogleListWidget()
{
	!bIsFolded ? FoldListWidget() : UnfoldListWidget();
	bIsFolded = !bIsFolded;
}

void UFriendListWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ListCollapser->OnClicked.AddDynamic(this, &UFriendListWidget::ToogleListWidget);
}

void UFriendListWidget::SetName(const FString& name)
{
	StatusName->SetText(FText::FromString(name));
}
