// Copyright _benui All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BUIScoreSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBUIOnScoreChangedSignature, int32, NewScore, int32, ScoreChange);

UCLASS()
class UBUIScoreSubsystem : public UWorldSubsystem
{
public:
private:
	GENERATED_BODY()

public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

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
	int32 Score = 0;
};