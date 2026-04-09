// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerActor01.h"

// Sets default values
ASpawnerActor01::ASpawnerActor01()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnerActor01::BeginPlay()
{
	Super::BeginPlay();
	
	//AActor* PlatformClass = (AActor*)GetWorld()->SpawnActor(AActor::get, FVector(0, 0, 0), FRotator::ZeroRotator);
	//ActorTest = UWorld::SpawnActor(Spawn, ,);
	
	for (auto a : ActorSpawnLocation)
		GetWorld()->SpawnActor<AActor>(TestClass, a->GetActorLocation(), FRotator::ZeroRotator);
}

// Called every frame
void ASpawnerActor01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

