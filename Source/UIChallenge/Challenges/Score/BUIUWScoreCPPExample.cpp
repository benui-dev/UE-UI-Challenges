// Copyright _benui All Rights Reserved.

// Example implementation of the Score challenge

#include "BUIUWScoreCPPExample.h"
#include "BUIScoreSubsystem.h"
#include "Components/TextBlock.h"

void UBUIUWScoreCPPExample::NativeConstruct()
{
	Super::NativeConstruct();

	UBUIScoreSubsystem* Subsystem = GetWorld()->GetSubsystem<UBUIScoreSubsystem>();
	Subsystem->OnScoreChangedDelegate.AddUniqueDynamic(this, &ThisClass::OnScoreChanged);
	
	ScoreLabel->SetText(FText::AsNumber(Subsystem->GetScore()));
}

void UBUIUWScoreCPPExample::OnScoreChanged(int32 NewScore, int32 ScoreChange)
{
	ScoreLabel->SetText(FText::AsNumber(NewScore));
}
