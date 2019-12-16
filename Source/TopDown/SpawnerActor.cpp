// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerActor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ASpawnerActor::ASpawnerActor() : _pos(FVector(0,0,100)), _color(FColor::Red), _spawnedActor(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_meshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Pyramid");

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/VREditor/BasicMeshes/SM_Pyramid_01.SM_Pyramid_01'"));
	UStaticMesh* Asset = MeshAsset.Object;

	_meshComponent->SetStaticMesh(Asset);

	SetPosition();


}

void ASpawnerActor::SetPosition() {
	switch (_direction)
	{
	case Spawn_Up:
		_pos = FTransform(FVector(0, 0, 200));
		break;
	case Spawn_Left:
		_pos = FTransform(FVector(0, -200, 0));
		break;
	case Spawn_Right:
		_pos = FTransform(FVector(0, 200, 0));
		break;
	case Spawn_Front:
		_pos = FTransform(FVector(200, 0, 0));
		break;
	case Spawn_Back:
		_pos = FTransform(FVector(-200, 0, 0));
		break;
	default:
		_pos = FTransform(FVector(0, 0, 200));
		break;
	}
}

// Called when the game starts or when spawned
void ASpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

#if WITH_EDITOR && ENABLE_DRAW_DEBUG
	if (IsSelectedInEditor()) {
		FTransform t = GetTransform();
		DrawDebugDirectionalArrow(GetWorld(), t.GetLocation(), (_pos * t).GetLocation(), 100.0f, _color);
	}
#endif

}

void ASpawnerActor::DestroySpawned() {
	if (_spawnedActor != nullptr) {
		_spawnedActor->Destroy();
		_spawnedActor = nullptr;
		OnActorSpawnedChanged(false);
	}
}

bool ASpawnerActor::IsSpawned() const {
	return _spawnedActor != nullptr;
}

void ASpawnerActor::SpawnActor() {
	FTransform spawned = GetTransform();
	spawned = _pos * spawned;

	_spawnedActor = GetWorld()->SpawnActor<AActor>(_class.Get(), 
		spawned);
	
	OnActorSpawnedChanged(true);
}

void ASpawnerActor::PostEditChangeProperty(FPropertyChangedEvent& event) {
	Super::PostEditChangeProperty(event);

#if WITH_EDITOR
	if (event.Property != nullptr && event.Property->GetFName().IsEqual(GET_MEMBER_NAME_CHECKED(ASpawnerActor, _class))) {
		if (_class == nullptr) {
			_color = FColor::Red;
		}
		else {
			_color = FColor::Green;
		}
	}

	if (event.Property != nullptr && event.Property->GetFName().IsEqual(GET_MEMBER_NAME_CHECKED(ASpawnerActor, _direction))) {
		SetPosition();
	}
#endif
}


