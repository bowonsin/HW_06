// Fill out your copyright notice in the Description page of Project Settings.


#include "Test.h"

// Sets default values
ATest::ATest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesch"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/Floor_400x400.Floor_400x400"));
	if (MeshAsset.Succeeded()) // 성공적으로 Meshasset을 가져왔는지 확인
	{
		// 가져왔다면 포인터화 했떤 mesh를 넣어줌
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Banana_A.M_Banana_A"));
	if (MaterialAsset.Succeeded())
	{
		// 첫번째 Materials를 설정하겠다 해서 첫번쨰 변수는 순서를 꼭 넣어야 적용이 된다
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Material Load Failed"));
	}

	// 기본 속도 값 초기화 
	f_RotationSpeed_roll = 50.0f;

	//UWorld::SpawnActor();
}

// Called when the game starts or when spawned
void ATest::BeginPlay()
{
	Super::BeginPlay();
	
	/*
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&ATest::MovingLocation,
		1.0f,
		true
	);
	*/
}
// Called every frame
void ATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovingRotator(DeltaTime);


}

void ATest::MovingLocation()
{
	AddActorLocalOffset(FVector(5.0f, 0, 0));
}
void ATest::MovingRotator(float DeltaTime)
{
	// 한방향으로만 회전 으로 첫 설정( 추가되는 되면 따로 주석 설정 할 것 ) 
	if (!FMath::IsNearlyZero(f_RotationSpeed_roll))
	{
		AddActorLocalRotation(FRotator(0,f_RotationSpeed_roll*DeltaTime,0));
	}
}

void ATest::Destroyed()
{
	Super::Destroyed();

	// 오브젝트가 파괴될 떄 타이머 clear 제거 해서 쓰레기 데이터 안나오게GetWorld
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	
}