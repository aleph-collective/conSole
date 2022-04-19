// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "conSole_Message.generated.h"

/**
 * 
 */
UCLASS()
class CONSOLE_API UconSole_Message : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		FString LogDate;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data", meta = (ExposeOnSpawn = true))
		FString Component;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data", meta = (ExposeOnSpawn = true))
		FString Code;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data", meta = (ExposeOnSpawn = true))
		FText LogMessage;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ColorCodes")
		FLinearColor Notice = FLinearColor(0, 95, 255, 1);
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ColorCodes")
		FLinearColor Message = FLinearColor(255, 255, 255, 1);
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ColorCodes")
		FLinearColor Warning = FLinearColor(1, 0.75, 0, 1);
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ColorCodes")
		FLinearColor Error = FLinearColor(1, 0, 0, 1);
};
