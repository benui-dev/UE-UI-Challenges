// Copyright _benui All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BUIUWScoreCPPExample.generated.h"

UCLASS()
class UBUIUWScoreCPPExample : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
	
	UFUNCTION()
	void OnScoreChanged(int32 NewScore, int32 ScoreChange);
	
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* ScoreLabel;
};
