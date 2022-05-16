// Fill out your copyright notice in the Description page of Project Settings.


#include "CSL_Window.h"
#include "TFileHelper.h"
#include "TimerManager.h"
#include "Engine/Engine.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetTextLibrary.h"

UScrollBox* messageBoxRef = nullptr;
TSubclassOf<class UconSole_Message> ConsoleMessageClass;
UconSole_Message* ConsoleMessage;

void UCSL_Window::SwitchCode()
{
	Code = CodeArray[CodeArrayIndex];
	if(CodeArrayIndex >= CodeArray.Num() - 1)
	{
		CodeArrayIndex = 0;
	} else
	{
		CodeArrayIndex = CodeArrayIndex + 1;
	}
	SwitchCodeColor();
}

void UCSL_Window::SwitchCodeColor()
{
	if(Code == "Notice")
	{
		CodeColor = FLinearColor(0, 95, 255);
	} else if (Code == "Warning")
	{
		CodeColor = FLinearColor(1, 0.75, 0);
	} else if (Code == "Error")
	{
		CodeColor = FLinearColor(1, 0, 0);
	} else if (Code == "Message" || Code == "Command")
	{
		CodeColor = FLinearColor(255, 255, 255);
	}
}

void UCSL_Window::PrintToConsole(FString InSender, FString InCode, FString InMessage)
{
	if(ConsoleMessageClass)
	{
		UWorld* World = GEngine->GameViewport->GetWorld();
		ConsoleMessage = CreateWidget<UconSole_Message>(World, ConsoleMessageClass);
		ConsoleMessage->SetSender(InSender);
		ConsoleMessage->SetCode(InCode);
		ConsoleMessage->SetMessage(InMessage);

		messageBoxRef->AddChild(ConsoleMessage);

		const FString OutputTimestamp = UKismetTextLibrary::AsDateTime_DateTime(FDateTime::Now()).ToString();

		FString OutputLog = FString::Printf(TEXT("%s: [%s]: (%s): %s"), *OutputTimestamp, *InSender, *InCode, *InMessage);
		if (InSender == "Client" || InSender == UKismetSystemLibrary::GetPlatformUserName() && InCode == "Notice") {
			UTFileHelper::SaveText(OutputLog.Append("\n"), *FString::Printf(TEXT("csl_%s_notice.txt"), FApp::GetProjectName()));
		}
		else {
			UTFileHelper::SaveText(OutputLog.Append("\n"), *FString::Printf(TEXT("csl_%s_log.log"), FApp::GetProjectName()));
		}

		FTimerHandle TimerHandle;

		World->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			messageBoxRef->ScrollToEnd();
		}, 0.02f, false);
	}
}

void UCSL_Window::ConfigConsoleReferences(UScrollBox* InMessageBox, TSubclassOf<UconSole_Message> InConsoleMessageClass)
{
	messageBoxRef = InMessageBox;
	ConsoleMessageClass = InConsoleMessageClass;
}
