// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerActor01.generated.h"

UCLASS()
class HW_06_API ASpawnerActor01 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerActor01();


	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item|Components")
	TSubclassOf<AActor> TestClass;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item|Components")
	TArray<AActor*> ActorSpawnLocation;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
