// Fill out your copyright notice in the Description page of Project Settings.


#include "TFileHelper.h"

bool UTFileHelper::LoadText(FString FileName, FString& Output)
{
	return FFileHelper::LoadFileToString(Output, *(FPaths::ProjectDir() + FileName));
}

bool UTFileHelper::SaveText(FString Input, FString FileName)
{
	return FFileHelper::SaveStringToFile(Input, *(FPaths::ProjectDir() + FileName), FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_Append);
}