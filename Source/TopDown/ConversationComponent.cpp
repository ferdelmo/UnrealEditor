// Fill out your copyright notice in the Description page of Project Settings.


#include "ConversationComponent.h"
#include "Engine/Engine.h"
#include "ConversationAsset.h"
#include "ConversationActor.h"

// Sets default values for this component's properties
UConversationComponent::UConversationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UConversationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UConversationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (setTimer) {
		timer -= DeltaTime;
		if (timer <= 0) {
			setTimer = false;
			const int32 AlwaysAddKey = -1;
			//CurrentLineFinished(timer);
			AConversationActor* ua = (AConversationActor *)GetOwner();
			ua->CurrentLineFinished(_state);
			//GEngine->AddOnScreenDebugMessage(AlwaysAddKey, 1.0f, FColor::Black, "NO FUNCIONA");

		}
	}

	// ...
}

void UConversationComponent::ShowCurrentLine() {
	if (_conversation != nullptr) {
		if (GEngine)
		{
			const int32 AlwaysAddKey = -1; // Passing -1 means that we will not try and overwrite an   
										  // existing message, just add a new one  
			FConversationLine cl = _conversation->_lines[_state];
			GEngine->AddOnScreenDebugMessage(AlwaysAddKey, cl.duration, cl.color, cl.text);
			setTimer = true;
			timer = cl.duration;
			timerLine = _state;
		}
	}
}

bool UConversationComponent::AdvanceConversation() {
	if (_conversation != nullptr) {
		int tam = _conversation->_lines.Num();
		if (_state < tam) {

			int offset = _conversation->_lines[_state].offset;

			if (_state + offset >= tam) {
				_state = 0;
				return true;
			}
			else {
				_state = _state + offset;
				return false;
			}
		}
		else {
			_state = 0;
			return false;
		}
	}
	else {
		return false;
	}
}

