// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"
#include "IAssetTypeActions.h"


class FTopDownEditorModule : public IModuleInterface {

public:
	void StartupModule() override;

	void ShutdownModule() override;

private:

	TSharedPtr<IAssetTypeActions> conversationActions;
};