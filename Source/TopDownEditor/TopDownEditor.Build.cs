// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TopDownEditor : ModuleRules
{
	public TopDownEditor (ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { 
        	"Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", 
        	"NavigationSystem", "AIModule" });

        PublicDependencyModuleNames.Add("TopDown");

        PrivateDependencyModuleNames.AddRange(new string[] { 
        	"UnrealEd", "XmlParser", "EditorStyle", "Slate", 
        	"SlateCore", "GraphEditor", "AppFramework"});

    }
}
