// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConversationActor.generated.h"

UCLASS()
class TOPDOWN_API AConversationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConversationActor();


	UFUNCTION(BlueprintImplementableEvent)
	void CurrentLineFinished(int _CurrentLine);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
