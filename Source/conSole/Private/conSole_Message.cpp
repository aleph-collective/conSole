// Fill out your copyright notice in the Description page of Project Settings.


#include "conSole_Message.h"

void UconSole_Message::SetSender(FString InSender)
{
	Sender = InSender;
}

void UconSole_Message::SetCode(FString InCode)
{
	Code = InCode;
}

void UconSole_Message::SetMessage(FString InMessage)
{
	LogMessage = InMessage;
}
