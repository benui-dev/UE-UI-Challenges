# Unreal UI Challenges

Improve your Unreal Engine UI skills by implementing a series of widgets.

## Installation

1. Fork the repository in GitHub or download a zip.
2. Install Unreal 5.0.3 or newer.
3. Open the UIChallenge.sln in Visual Studio or open the .uproject in Rider.
4. Build and run the project.

## How to participate in the challenges

Each challenge should have its own `UWorldSubsystem` containing all the data
that you need to complete it.

For example, the Score challenge has `UBUIScoreSubsystem` that has:
* `GetScore()`, a function callable from C++ and Blueprints for getting the
  current score.
* `OnScoreChangedDelegate`, a delegate/event that is triggered when the score
  changes.

```cpp
UBUIScoreSubsystem* Subsystem = GetWorld()->GetSubsystem<UBUIScoreSubsystem>();
Subsystem->OnScoreChangedDelegate.AddUniqueDynamic(this, &ThisClass::OnScoreChanged);
	
ScoreLabel->SetText(FText::AsNumber(Subsystem->GetScore()));
```

## More information

For more information on the challenges themselves see the [UI Challenges](https://benui.ca/unreal/ui-challenges) page.
