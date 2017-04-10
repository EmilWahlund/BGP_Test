// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "SoLMode.generated.h"


UCLASS()
class BGP_TEST_API ASoLMode : public AGameMode
{
	GENERATED_BODY()
	
		ASoLMode(const FObjectInitializer& ObjectInitializer);
	
		virtual void StartPlay() override;
	
};
