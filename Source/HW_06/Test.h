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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	

	// Edit 모두에 있고 , 블루프린트에서 Get,Set 가능 , 카테고리는 Item 위치
	// - pitch (y축)  , yaw(z축)  ,roll (x축)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	float f_RotationSpeed_roll;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	float f_RotationSpeed_yaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	float f_RotationSpeed_pitch;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;
	
	void MovingRotator(float DeltaTime);
	void MovingLocation();


private:

	FTimerHandle TimerHandle;
	
};
