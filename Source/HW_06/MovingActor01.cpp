// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor01.h"

// Sets default values
AMovingActor01::AMovingActor01()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesch"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("'/Game/Resources/Props/SM_TableRound.SM_TableRound'"));
	if (MeshAsset.Succeeded()) // 성공적으로 Meshasset을 가져왔는지 확인
	{
		// 가져왔다면 포인터화 했떤 mesh를 넣어줌
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("'/Game/Resources/Materials/M_Banana_A.M_Banana_A'"));
	if (MaterialAsset.Succeeded())
	{
		// 첫번째 Materials를 설정하겠다 해서 첫번쨰 변수는 순서를 꼭 넣어야 적용이 된다
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

}

// Called when the game starts or when spawned
void AMovingActor01::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	// 속도 
	f_Speed_x = 100.0f;

	// 최대 거리
	MaxRange = 400.0f;
	f_Direction = 1;
}

// Called every frame
void AMovingActor01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	MovingLocation(DeltaTime);
	
}

void AMovingActor01::MovingLocation(float DeltaTime) // 이동 관련 
{

	if (!FMath::IsNearlyZero(f_Speed_x))
	{
		// 이동
		AddActorLocalOffset(FVector(f_Direction * f_Speed_x * DeltaTime, 0, 0));

		// 거리 계산 (시작 위치 기준) 
		float Distance = GetActorLocation().X - StartLocation.X;

		// 범위 초과 시 방향 반전
		if (Distance >= MaxRange || Distance <= -MaxRange)
		{
			f_Direction *= -1;
		}
	}
}