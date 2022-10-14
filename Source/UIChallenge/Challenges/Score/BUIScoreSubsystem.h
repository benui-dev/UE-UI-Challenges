// Copyright _benui All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BUIScoreSubsystem.generated.h"

DECLARE_STATS_GROUP(TEXT("UI Challenge Score"), STATGROUP_UICHALLENGE_SCORE, STATCAT_Advanced)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBUIOnScoreChangedSignature, int32, NewScore, int32, ScoreChange);

UCLASS()
class UBUIScoreSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
public:
	UBUIScoreSubsystem();

	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void Tick(float DeltaTime) override;

	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(UBUIScoreSubsystem, STATGROUP_UICHALLENGE_SCORE);
	}

	UFUNCTION(BlueprintCallable, Category="Score")
	int32 GetScore() const;

	// If points is <= 0, a random amount is chosen
	UFUNCTION(BlueprintCallable, Category="Score")
	void AddScore(int32 Points = -1);

	UFUNCTION(BlueprintCallable, Category="Score")
	void ResetScore();

	UPROPERTY(BlueprintAssignable, Category="Score")
	FBUIOnScoreChangedSignature OnScoreChangedDelegate;

protected:
	int32 Score;

	float TimeLeftToNextScoreIncrease;
	float MinScoreChangeDuration;
	float MaxScoreChangeDuration;
};
