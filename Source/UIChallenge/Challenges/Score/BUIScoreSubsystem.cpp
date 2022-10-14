// Copyright _benui All Rights Reserved.

#include "BUIScoreSubsystem.h"

UBUIScoreSubsystem::UBUIScoreSubsystem()
	: Score(0)
	  , TimeLeftToNextScoreIncrease(INDEX_NONE)
	  , MinScoreChangeDuration(0.2f)
	  , MaxScoreChangeDuration(1.0f)
{
}

void UBUIScoreSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	Score = FMath::RandRange(1, 9999);
	OnScoreChangedDelegate.Broadcast(Score, Score);
}

void UBUIScoreSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeLeftToNextScoreIncrease -= DeltaTime;
	if (TimeLeftToNextScoreIncrease <= 0)
	{
		AddScore();
		TimeLeftToNextScoreIncrease = FMath::FRandRange(MinScoreChangeDuration, MaxScoreChangeDuration);
	}
}

int32 UBUIScoreSubsystem::GetScore() const
{
	return Score;
}

void UBUIScoreSubsystem::AddScore(int32 Points)
{
	if (Points <= 0)
	{
		Points = FMath::RandRange(1, 9999);
	}
	Score += Points;
	OnScoreChangedDelegate.Broadcast(Score, Points);
}

void UBUIScoreSubsystem::ResetScore()
{
	const int32 OldScore = Score;
	Score = 0;
	OnScoreChangedDelegate.Broadcast(Score, -OldScore);
}
