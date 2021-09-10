// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "FriendProfile.generated.h"

/**
 *  -Nombre, (OPC: icono de plataforma), booleano connected, y mas info que quiera.
      -Que llene los datos y marque algunos como connected y otros disconnected
 */

USTRUCT(BlueprintType)
struct FFriendProfileStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Connected;
};

UCLASS()
class UMGEXCERCISE_API UFriendProfile : public UObject
{
	GENERATED_BODY()
	
};
