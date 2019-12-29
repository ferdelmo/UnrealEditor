// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"
#include "IAssetTypeActions.h"
#include "HAL/IConsoleManager.h"
#include "TopDown/ConversationAsset.h"

class TOPDOWNEDITOR_API FTopDownEditorModule : public IModuleInterface {

public:
	void StartupModule() override;

	void ShutdownModule() override;

	//DECLARE_DELEGATE_TwoParams("DoSpawn", const TArray<FString>&, UWorld*)
	void CommandDoSpawn(const TArray<FString>& _arrParams, UWorld* _pWorld);

	void CommandToolbar();

private:

	TSharedPtr<IAssetTypeActions> conversationActions;

	TCHAR* commandName;

	TSharedPtr<FExtender> extender;

	TArray<UConversationAsset*> _model;

};