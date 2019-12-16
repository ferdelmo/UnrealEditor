// Fill out your copyright notice in the Description page of Project Settings.


#include "ConversationAssetActions.h"
#include "TopDown/ConversationAsset.h"
#include "BlueprintActionMenuBuilder.h"
#include "MultiBoxBuilder.h"
#include "EditorStyle.h"

FConversationAssetActions::FConversationAssetActions()
{
	
}

FConversationAssetActions::~FConversationAssetActions()
{
}

FText FConversationAssetActions::GetName() const {
	return FText::FromString("Conversation");
}

UClass* FConversationAssetActions::GetSupportedClass() const {
	return UConversationAsset::StaticClass();
}

FColor FConversationAssetActions::GetTypeColor() const {
	return FColor::Red;
}

uint32 FConversationAssetActions::GetCategories() {
	return EAssetTypeCategories::Misc;
}

FText FConversationAssetActions::GetAssetDescription(const FAssetData& AssetData) const {
	return  FText::FromString("Asset that store a conversation, compose by a list of lines, each of them with different text, color, duration and offset");
}

bool FConversationAssetActions::HasActions(const TArray<UObject*>& InObjects) const {
	return true;
}


void InvertConversationActionClicked() {

}

void FConversationAssetActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) {
	//MenuBuilder.AddMenuEntry(FExecuteAction::CreateRaw(this, InvertConversationActionClicked),
		//FText::FromString(TEXT("Inverse")), FText::FromString(TEXT("Inverse the lines of the conversation")), FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions"));
	//MenuBuilder.AddMenuEntry(FText::FromString(TEXT("Inverse")),)
}

