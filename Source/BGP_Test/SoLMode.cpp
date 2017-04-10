// Fill out your copyright notice in the Description page of Project Settings.

#include "BGP_Test.h"
#include "SoLMode.h"
#include "MyPlayer.h"


ASoLMode::ASoLMode(const class FObjectInitializer& ObjectInitializer)	: Super(ObjectInitializer)
{
	DefaultPawnClass = AMyPlayer::StaticClass();
}

void ASoLMode::StartPlay()
{
	Super::StartPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("this is a test"));
		
	}

	//StartMatch();

	//GEngine
}

