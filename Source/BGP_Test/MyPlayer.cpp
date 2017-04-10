#include "BGP_Test.h"
#include "MyPlayer.h"

AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	tmp = false;
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	//movement
	InputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
	//camera
	InputComponent->BindAxis("Turn", this, &AMyPlayer::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AMyPlayer::AddControllerPitchInput);
	//jump
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayer::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMyPlayer::OnStopJump);

	InputComponent->BindAction("Crouch", IE_Pressed, this, &AMyPlayer::ToggleCrouch);

}

void AMyPlayer::MoveForward(float amount)
{
	
	if ((Controller != NULL) && (amount != 0.0f))
	{
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, amount);
	}
}

void AMyPlayer::MoveRight(float amount)
{
	if ((Controller != NULL) && (amount != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, amount);
	}
}

void AMyPlayer::OnStartJump()
{
	bPressedJump = true;
}
void AMyPlayer::OnStopJump()
{
	bPressedJump = false;
}

void AMyPlayer::ToggleCrouch()
{
	int NewHeight = BaseEyeHeight;
	
	if(CanCrouch() == true && NewHeight > CrouchedEyeHeight)
	{
		do
		{
			FEvent::Wait(100, bIsCrouched);
			NewHeight -= 1;
			BaseEyeHeight = NewHeight;
		} while (NewHeight > CrouchedEyeHeight);
		tmp = true;
		if (tmp == true)
		{
			Crouch();
		}
	}
	else
	{
		UnCrouch();
		tmp = false;
	}
}
