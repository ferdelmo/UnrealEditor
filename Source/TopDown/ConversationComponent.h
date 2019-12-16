// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ConversationComponent.generated.h"

class UConversationAsset;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPDOWN_API UConversationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UConversationComponent();

	UFUNCTION(BlueprintCallable)
	void ShowCurrentLine();

	//Return true if the conversation si over
	UFUNCTION(BlueprintCallable)
	bool AdvanceConversation();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category="Conversation")
	UConversationAsset* _conversation;

	UPROPERTY(EditAnywhere, Category = "Conversation")
	int _state;

	float timer = -1;
	bool setTimer = false;
	int timerLine = 0;
};
