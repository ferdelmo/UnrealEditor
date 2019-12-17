// Fill out your copyright notice in the Description page of Project Settings.


#include "ConversationAssetActions.h"
#include "TopDown/ConversationAsset.h"
#include "MultiBoxBuilder.h"
#include "EditorStyle.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "Modules/ModuleManager.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/SListView.h"

FConversationAssetActions::FConversationAssetActions()
{
	
}

FConversationAssetActions::~FConversationAssetActions()
{
}

FText FConversationAssetActions::GetName() const {
	
	return FText::FromString("Conversation"); // FText::FromString("Conversation");
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


void FConversationAssetActions::InvertConversationActionClicked() {

	if (FModuleManager::Get().IsModuleLoaded("ContentBrowser")) {
		FContentBrowserModule& cbmodule = FModuleManager::Get().GetModuleChecked<FContentBrowserModule>("ContentBrowser");

		IContentBrowserSingleton& cbsingleton = cbmodule.Get();

		TArray<FAssetData> conversations;
		cbsingleton.GetSelectedAssets(conversations);

		for (int i = 0; i < conversations.Num(); i++) {
			FAssetData aux = conversations[i];
			if(aux.IsAssetLoaded() && aux.GetClass() == UConversationAsset::StaticClass()){
				UConversationAsset * ca = (UConversationAsset *)aux.GetAsset();
				ca->Inverse();
			}
		}
	}
	else {

	}
}

void FConversationAssetActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) {
	MenuBuilder.AddMenuEntry(FText::FromString(TEXT("Inverse")), FText::FromString(TEXT("Inverse the lines of the conversation")),
		FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions"), FExecuteAction::CreateRaw(this, &FConversationAssetActions::InvertConversationActionClicked));
}


TSharedPtr<SWidget> FConversationAssetActions::GetThumbnailOverlay(const FAssetData& AssetData) const {

	FText lines = FText::FromString("ERROR.");
	FText name = FText::FromString("ERROR.");
	if (AssetData.GetClass() == UConversationAsset::StaticClass()) {
		UConversationAsset* conv = (UConversationAsset*)AssetData.GetAsset();

		FString s = "Lines: ";
		s.Append(FString::FromInt(conv->_lines.Num()));
		lines = FText::FromString(s);
		name = FText::FromString(conv->_name);
	}
	

	TSharedPtr<SWidget> stb =  SNew(SHorizontalBox)
		+ SHorizontalBox::Slot().Padding(2, 5)
		[

			SNew(SVerticalBox)
			/*+ SVerticalBox::Slot().VAlign(VAlign_Top)
		[
			SNew(STextBlock).Text(FText::FromString("Conversation")).AutoWrapText(true)
			.Justification(ETextJustify::Center)
		]*/
			+ SVerticalBox::Slot().VAlign(VAlign_Top)
		[
			SNew(STextBlock).Text(name).AutoWrapText(true)
			.WrappingPolicy(ETextWrappingPolicy::AllowPerCharacterWrapping)
				.Justification(ETextJustify::Center)
		]
			+ SVerticalBox::Slot().VAlign(VAlign_Bottom)
		[
			SNew(STextBlock).Text(lines).AutoWrapText(true)
			.Justification(ETextJustify::Center)
		]
		];
	
	

	return TSharedPtr<SWidget>(stb);

}

