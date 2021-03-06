// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Framework/Commands/Commands.h"

class TOPDOWNEDITOR_API FTopDownEditorCommands : public  TCommands<FTopDownEditorCommands> {

public:
	FTopDownEditorCommands();

	virtual void RegisterCommands() override;

	TSharedPtr<FUICommandInfo> conversationWindowCommand;
};