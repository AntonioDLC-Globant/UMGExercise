// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendEntryWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "FriendInfoTooltip.h"

void UFriendEntryWidget::OnHovered()
{
	Tooltip = CreateWidget<UFriendInfoTooltip>(this, FriendInfoTooltipClass);
	Tooltip->AddToViewport();
	Tooltip->Username->SetText(Name->GetText());
	Tooltip->UpdatePosition();
}

void UFriendEntryWidget::OnUnhovered()
{
	Tooltip->RemoveFromParent();
}

void UFriendEntryWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	HoverArea->OnHovered.AddDynamic(this, &UFriendEntryWidget::OnHovered);
	HoverArea->OnUnhovered.AddDynamic(this, &UFriendEntryWidget::OnUnhovered);
}