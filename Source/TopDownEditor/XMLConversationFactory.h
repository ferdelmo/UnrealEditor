// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "XMLConversationFactory.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNEDITOR_API UXMLConversationFactory : public UFactory
{
	GENERATED_BODY()
public:
	UXMLConversationFactory();

	UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
		const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
	
};
