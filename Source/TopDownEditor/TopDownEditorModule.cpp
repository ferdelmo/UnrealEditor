// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownEditorModule.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"
#include "ConversationAssetActions.h"

IMPLEMENT_MODULE(FTopDownEditorModule, TopDownEditor)

void FTopDownEditorModule::StartupModule() {

	FAssetToolsModule& oToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
	IAssetTools& oAssetToolsModule = oToolsModule.Get();

	conversationActions = MakeShareable(new FConversationAssetActions());

	oAssetToolsModule.RegisterAssetTypeActions(conversationActions.ToSharedRef());
}

void FTopDownEditorModule::ShutdownModule() {

	if (FModuleManager::Get().IsModuleLoaded("AssetTools")) {

		IAssetTools& assetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>(
			"AssetTools").Get();

		assetTools.UnregisterAssetTypeActions(conversationActions.ToSharedRef());
	}


	conversationActions.Reset();
}
