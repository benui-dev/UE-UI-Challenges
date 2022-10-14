// Copyright _benui All Rights Reserved.

#include "BUIScoreSubsystem.h"

bool UBUIScoreSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UBUIScoreSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	Score = FMath::RandRange(1,9999);
	OnScoreChangedDelegate.Broadcast(Score, Score);
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
