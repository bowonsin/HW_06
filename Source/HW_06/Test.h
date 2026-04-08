// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test.generated.h"

UCLASS()
class HW_06_API ATest : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ATest();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(VisibleAnywhere)
	float f_RotationSpeed_roll;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MovingRotator(float DeltaTime);
	void MovingLocation();

private:

	FTimerHandle TimerHandle;
	// - pitch (y축)  , yaw(z축)  ,roll (x축)
	
};
