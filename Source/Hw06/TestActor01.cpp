// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor01.h"

// Sets default values
ATestActor01::ATestActor01()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor01::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

