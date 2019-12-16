// Fill out your copyright notice in the Description page of Project Settings.


#include "XMLConversationFactory.h"
#include "TopDown/ConversationAsset.h"
#include "XmlFile.h"



UXMLConversationFactory::UXMLConversationFactory() {
	SupportedClass = UConversationAsset::StaticClass();
	bCreateNew = false;
	bEditAfterNew = true;
	bEditorImport = true;
	Formats.Add("xml;xml conversation file");

}

UObject* UXMLConversationFactory::FactoryCreateFile(UClass* InClass, UObject* InParent,	FName InName,	EObjectFlags Flags,
	const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) {

	UConversationAsset * conv = NewObject<UConversationAsset>(InParent, InClass, InName, Flags);
	if (conv == nullptr) {
		return conv;
	}

	FXmlFile file(Filename);

	FXmlNode* root = file.GetRootNode();
	TArray<FXmlNode *> childs = root->FindChildNode("Lines")->GetChildrenNodes();

	conv->_name = root->GetAttribute("name");
	for (int i = 0; i < childs.Num(); i++) {
		FConversationLine line;
		FXmlNode* node = childs[i];
		line.text = node->GetContent();
		line.color = FColor::FromHex(node->GetAttribute("color"));
		line.duration = FCString::Atof(*(node->GetAttribute("duration")));
		line.offset = FCString::Atoi(*(node->GetAttribute("offset")));

		conv->_lines.Add(line);
	}

	return conv;
}