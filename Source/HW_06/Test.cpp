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
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("'/Game/Resources/Props/SM_CornerFrame.SM_CornerFrame'"));
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
void ATest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

