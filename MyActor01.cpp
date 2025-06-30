#include "MyActor01.h"
#include "Engine/Engine.h"

// 생성자
AMyActor01::AMyActor01()
{
	PrimaryActorTick.bCanEverTick = true;
}

// BeginPlay
void AMyActor01::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay Called"));

	Move(); // Move 함수 호출
}

// Tick (프레임마다 호출되며 현재는 사용 안 함)
void AMyActor01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 일정한 Step 거리 반환
double AMyActor01::Step()
{
	return 10.0;
}

// 이동 함수: 로그 출력
void AMyActor01::Move()
{
	FVector Location = FVector::ZeroVector;

	UE_LOG(LogTemp, Warning, TEXT("Start Location: (%.2f, %.2f)"), Location.X, Location.Y);

	for (int32 i = 0; i < 5; ++i)
	{
		Location += FVector(Step(), Step(), 0.0);
		UE_LOG(LogTemp, Warning, TEXT("Step %d: (%.2f, %.2f)"), i + 1, Location.X, Location.Y);
	}
}
