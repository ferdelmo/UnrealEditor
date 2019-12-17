// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownEditorModule.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"
#include "ConversationAssetActions.h"
#include "EngineUtils.h"
#include "TopDown/SpawnerActor.h"
#include "HAL/ConsoleManager.h"
#include "TopDownEditorCommands.h"

IMPLEMENT_MODULE(FTopDownEditorModule, TopDownEditor)

void FTopDownEditorModule::StartupModule() {


	//ADD asset tools module
	FAssetToolsModule& oToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
	IAssetTools& oAssetToolsModule = oToolsModule.Get();


	conversationActions = MakeShareable(new FConversationAssetActions());

	oAssetToolsModule.RegisterAssetTypeActions(conversationActions.ToSharedRef());

	//Register command
	commandName = TEXT("DoSpawn");


	IConsoleManager::Get().RegisterConsoleCommand(commandName, TEXT("USE: DoSpawn actor_name"),
		FConsoleCommandWithWorldAndArgsDelegate::CreateRaw(this, &FTopDownEditorModule::CommandDoSpawn), ECVF_Default);
	
	//toolbar

	FTopDownEditorCommands::Register();

	FUICommandList* commandList = new FUICommandList();

	commandList->MapAction(FTopDownEditorCommands::Get().conversationWindowCommand,
		FExecuteAction::CreateRaw(this, &FTopDownEditorModule::CommandToolbar));

	extender = MakeShareable(new FExtender());
	TSharedPtr<FUICommandList> auxCommand = MakeShareable(new FUICommandList());
	extender.Get()->AddToolBarExtension("TopDown", EExtensionHook::After, auxCommand,
		);

}

void FTopDownEditorModule::ShutdownModule() {

	if (FModuleManager::Get().IsModuleLoaded("AssetTools")) {

		IAssetTools& assetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>(
			"AssetTools").Get();

		assetTools.UnregisterAssetTypeActions(conversationActions.ToSharedRef());
	}

	conversationActions.Reset();

	IConsoleManager& consoleManager = IConsoleManager::Get();

	consoleManager.UnregisterConsoleObject(commandName);
}


void  FTopDownEditorModule::CommandDoSpawn(const TArray<FString>& _arrParams, UWorld* _pWorld) {
	if (_arrParams.Num() > 1 || _arrParams.Num() < 1) {
		return;
	}

	for (TActorIterator<ASpawnerActor> ActorItr(_pWorld); ActorItr; ++ActorItr) {
		FString name = ActorItr->GetName();
		if (name.Equals(_arrParams[0])) {
			ActorItr->SpawnActor();
		}
	}
}

void FTopDownEditorModule::CommandToolbar() {

}
