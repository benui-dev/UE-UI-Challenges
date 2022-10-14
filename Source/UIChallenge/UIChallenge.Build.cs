// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UIChallenge : ModuleRules
{
	public UIChallenge(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"Slate",
			"SlateCore",
			"UMG"
		});
	}
}