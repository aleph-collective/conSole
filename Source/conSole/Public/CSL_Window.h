// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "conSole_Message.h"
#include "Components/ScrollBox.h"
#include "WinMan.h"
#include "CSL_Window.generated.h"

/**
 * 
 */
UCLASS()
class CONSOLE_API UCSL_Window : public UWinMan
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Data")
		FString Code;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Data")
		FLinearColor CodeColor = FLinearColor(255,255,255);
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Data")
		TArray<FString> CodeArray{
			"Notice",
			"Message",
			"Warning",
			"Command",
			"Error"
		};
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Data")
		int CodeArrayIndex;

	UFUNCTION(BlueprintCallable, Category = "conSole")
		void SwitchCode();
		void SwitchCodeColor();
	UFUNCTION(BlueprintCallable, Category = "conSole")
		static void PrintToConsole(FString InSender, FString InCode, FString InMessage);
	UFUNCTION(BlueprintCallable, Category = "conSole: Setup")
		void ConfigConsoleReferences(UScrollBox* InMessageBox, TSubclassOf<class UconSole_Message> InConsoleMessageClass);
};
