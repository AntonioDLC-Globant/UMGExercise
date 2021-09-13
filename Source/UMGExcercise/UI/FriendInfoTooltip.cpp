// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendInfoTooltip.h"

void UFriendInfoTooltip::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::Tick(MyGeometry, InDeltaTime);
	UpdatePosition();
}

void UFriendInfoTooltip::UpdatePosition()
{
	FVector2D Position;
	GetWorld()->GetGameViewport()->GetMousePosition(Position);
	SetPositionInViewport(Position + Offset);
}