// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/AssetTypeActions_Base.h"
#include "Widgets/SWidget.h"

/**
 * 
 */
class TOPDOWNEDITOR_API FConversationAssetActions : public FAssetTypeActions_Base
{

public:
	FConversationAssetActions();
	~FConversationAssetActions();

	FText GetName() const override;

	UClass* GetSupportedClass() const override;

	FColor GetTypeColor() const override;
	
	uint32 GetCategories() override;
	
	FText GetAssetDescription(const FAssetData& AssetData) const override;

	bool HasActions(const TArray<UObject*>& InObjects) const override;

	
	void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;

	void InvertConversationActionClicked();

	TSharedPtr<SWidget> GetThumbnailOverlay(const FAssetData& AssetData) const override;
};
