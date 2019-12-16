// Fill out your copyright notice in the Description page of Project Settings.


#include "ConversationFactory.h"
#include "TopDown/ConversationAsset.h"
#include "UObject/UObjectGlobals.h"
#include "FeedbackContext.h"

UConversationFactory::UConversationFactory() {
	SupportedClass = UConversationAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UConversationFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {

	UConversationAsset* ca(nullptr);
	if (Warn->YesNof(FText::FromString(TEXT("Are you sure?")))) {
		ca = NewObject<UConversationAsset>(InParent, InClass, InName, Flags);
	}
	return ca;
}