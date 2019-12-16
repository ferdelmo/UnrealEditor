// Fill out your copyright notice in the Description page of Project Settings.


#include "ConversationAsset.h"

UConversationAsset::UConversationAsset() : _lines(TArray<FConversationLine>()), _name(FString()) {

}


UConversationAsset::UConversationAsset(FString name) : _lines(TArray<FConversationLine>()), _name(name) {

}

UConversationAsset::UConversationAsset(FString name, TArray <FConversationLine> lines) : _lines(lines), _name(name) {

}

void UConversationAsset::Inverse() {
	int ini = 0;
	int fin = _lines.Num()-1;
	while (ini < fin) {
		FConversationLine aux = _lines[ini];
		_lines[ini] = _lines[fin];
		_lines[fin] = aux;
		++ini;
		--fin;
	}
}
