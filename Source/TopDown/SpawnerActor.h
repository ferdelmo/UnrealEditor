// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "Tickable.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

#include "SpawnerActor.generated.h"

class UStaticMeshComponent;


UENUM(BlueprintType)
enum ESpawnDirection { 
	Spawn_Up, 
	Spawn_Left, 
	Spawn_Right,
	Spawn_Front,
	Spawn_Back
};

UCLASS()
class TOPDOWN_API ASpawnerActor : public AActor, public FTickableGameObject
{
	GENERATED_BODY()
	
public:	


	// Sets default values for this actor's properties
	ASpawnerActor();
	
	//UPROPERTY(EditAnywhere, Category = "Spawner")
		FTransform _pos;
	UPROPERTY(EditAnywhere, Category = "Spawner")
		TSubclassOf<AActor> _class;

	UFUNCTION(BlueprintCallable)
		void SpawnActor();

	UFUNCTION(BlueprintCallable)
		void DestroySpawned();

	UFUNCTION(BlueprintCallable)
		bool IsSpawned() const;


	UFUNCTION(BlueprintImplementableEvent)
		void OnActorSpawnedChanged(bool spawned);

	UPROPERTY(EditAnywhere, Category = "Spawner")
		TEnumAsByte< ESpawnDirection > _direction;

	TStatId GetStatId() const override { return {}; }

	bool IsTickableInEditor() const override { return true; }

	virtual void PostEditChangeProperty(FPropertyChangedEvent& event) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetPosition();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	FColor _color;
	UStaticMeshComponent* _meshComponent;

	AActor* _spawnedActor;


};
