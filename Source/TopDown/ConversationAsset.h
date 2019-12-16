// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ConversationAsset.generated.h"

USTRUCT(BlueprintType)
struct TOPDOWN_API FConversationLine {

	GENERATED_BODY()

	UPROPERTY(EditAnyWhere, Category = "ConversationLine")
	FString text;

	UPROPERTY(EditAnyWhere, Category = "ConversationLine")
	FColor color = FColor::Black;

	UPROPERTY(EditAnyWhere, Category = "ConversationLine")
	float duration = 3;

	UPROPERTY(EditAnyWhere, Category = "ConversationLine")
	int offset = 1;
};

/**
 * 
 */
UCLASS(BlueprintType)
class TOPDOWN_API UConversationAsset : public UObject
{
public:
	GENERATED_BODY()

	UConversationAsset();

	UConversationAsset(FString name);

	UConversationAsset(FString name, TArray <FConversationLine> lines);

	void Inverse();

public:
	UPROPERTY(EditAnywhere, Category = "Conversation")
	FString _name;

	UPROPERTY(EditAnywhere, Category = "Conversation")
	TArray<FConversationLine> _lines;


	
};
