// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class BGP_TEST_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMyPlayer();
	UPROPERTY(EditAnywhere)
		ACharacter* test;
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	UFUNCTION()
		void MoveForward(float amount);
	UFUNCTION()
		void MoveRight(float amount);
	UFUNCTION()
		void OnStartJump();
	UFUNCTION()
		void OnStopJump();
	UFUNCTION()
		void ToggleCrouch();
private:
	bool tmp;
};
