// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownEditorCommands.h"
#include "UICommandList.h"
#include "EditorStyleSet.h"

FTopDownEditorCommands::FTopDownEditorCommands() : 
	TCommands<FTopDownEditorCommands>(
		FName("TopDownEditor"), FText::FromString("Commnads from the top down custom editor"),
		NAME_None, FEditorStyle::GetStyleSetName()) {
	
}

void FTopDownEditorCommands::RegisterCommands() {
#define LOCTEXT_NAMESPACE ""
	UI_COMMAND(conversationWindowCommand, "Conversation", "Description of what my stuff is doing.",
		EUserInterfaceActionType::Button, FInputGesture());
#undef LOCTEXT_NAMESPACE
}