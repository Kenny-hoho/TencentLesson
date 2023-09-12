// Copyright Epic Games, Inc. All Rights Reserved.

#include "TencentLessonGameMode.h"
#include "TencentLessonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATencentLessonGameMode::ATencentLessonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
