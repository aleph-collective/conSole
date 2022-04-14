// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TFileHelper.generated.h"

/**
 * 
 */
UCLASS()
class CONSOLE_API UTFileHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Custom")
		static bool LoadText(FString FileName, FString& Output);
	UFUNCTION(BlueprintCallable, Category = "Custom")
		static bool SaveText(FString Input, FString FileName);
};
