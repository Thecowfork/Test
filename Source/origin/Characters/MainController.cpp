// Fill out your copyright notice in the Description page of Project Settings.


#include "MainController.h"//this header must be first include!!!



AMainController::AMainController()
{
	this->Construct();
}
// Called when the game starts or when spawned
void AMainController::BeginPlay()
{
	Super::BeginPlay();
	MainPlayer = Cast<AmainCharacter>(GetCharacter());
}
// Called every frame
void AMainController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->AnimSwitch();
}

// Called to bind functionality to input
void AMainController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//��������ӳ��
	//Mouse
	InputComponent->BindAction("MouseWhellUp", IE_Pressed, this, &AMainController::MouseWheelUp);
	InputComponent->BindAction("MouseWhellDown", IE_Pressed, this, &AMainController::MouseWheelDown);
	InputComponent->BindAction("MouseBtnMiddle", IE_Pressed, this, &AMainController::MouseBtnMiddle);
	InputComponent->BindAction("MouseBtnLeft", IE_Pressed, this, &AMainController::MouseBtnLeft);
	InputComponent->BindAction("MouseBtnRight", IE_Pressed, this, &AMainController::MouseBtnRight);

	//Key or Inventory
	InputComponent->BindAction("KeyOne", IE_Pressed, this, &AMainController::KeyOne);
	InputComponent->BindAction("ChangeView", IE_Pressed, this, &AMainController::ChangeView);
	//Character's action

	InputComponent->BindAxis("MoveForward", this, &AMainController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainController::MoveRight);

	InputComponent->BindAction("Run", IE_Pressed,this, &AMainController::Run);
	InputComponent->BindAction("StopRun", IE_Released, this, &AMainController::StopRun);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMainController::Jump);
	InputComponent->BindAction("StopJumping", IE_Released, this, &AMainController::StopJumping);
	/*InputComponent->BindAction("Crouch", IE_Pressed, this, &AMainController::Crouch);
	InputComponent->BindAction("StopCrouch", IE_Released, this, &AMainController::StopCrouch);
	InputComponent->BindAction(" Lie", IE_Pressed, this, &AMainController::Lie);
	InputComponent->BindAction("StopLie", IE_Released, this, &AMainController::StopLie);
	*/


}
void AMainController::Construct()
{

	InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("InputComponent"));

}
void AMainController::MouseWheelUp()
{

}
void AMainController::MouseWheelDown()
{

}
void AMainController::MouseBtnLeft()
{

}
void AMainController::MouseBtnRight()
{

}
void AMainController::MouseBtnMiddle()
{

}
//Key or Inventory
void AMainController::KeyOne()
{

}
void AMainController::ChangeView()
{
	isFirstView = !isFirstView;
	if (isFirstView)
	{
		MainPlayer->SpringArmComponent->TargetArmLength = 0;
		MainPlayer->FirstPerson();
	}
	else
	{
		MainPlayer->SpringArmComponent->TargetArmLength = 400;//���ñ۳�
		MainPlayer->ThirdPerson();
	}
}

void AMainController::AnimSwitch()
{
	//�����л�
	bool IsFalling = MainPlayer->GetCharacterMovement()->IsFalling();
	bool IsCrouching = MainPlayer->GetCharacterMovement()->IsCrouching();
	bool IsPlaying = MainPlayer->GetMesh()->IsPlaying();//�����Ƿ��ڲ���
	bool IsJumpStart = MainPlayer->GetPlayingAnimName() == MainPlayer->role_Jump;//�Ƿ�Ϊ����
	if (IsFalling && CanJump)
	{
		//�л����䶯��
		CanJump = false;
		CanRun = true;
		CanIdle = true;
		//CanLie = false;
		//CanCrouch = false;
		if (IsJumpStart && !IsPlaying)
		{
			MainPlayer->AnimPlay(MainPlayer->role_JumpLoop);
		}
	}
	else if (ForwardValue != 0 || RightValue != 0)
	{
		//�л��ܲ�
		if (!IsFalling && CanRun)
		{
			CanRun = false;
			CanJump = true;
			CanIdle = true;
			//CanCrouch = true;
			//CanLie = true;

			if (IsCrouching)
			{
				// ���������߶���
			}
			else
			{
				//�ٶ��㹻����ܲ�

				MainPlayer->AnimPlay(MainPlayer->role_Run, true);
			}
		}
		

	}
	else
	{
		// ��������
		if (!IsFalling && CanIdle)
		{
			CanRun = true;
			CanJump = true;
			CanIdle = false;
			//CanCrouch = true;
			//CanLie = true;
			if (IsCrouching)
			{
				//�������´�������
			}
			else
			{
				MainPlayer->AnimPlay(MainPlayer->role_Idle, true);
			}
		}
	}
}
//Character's action
void AMainController::MoveForward(float value)
{
	ForwardValue = value;
	if (value != 0)
	{
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);//��ȡX��
		MainPlayer->AddMovementInput(Direction, value);//��

	}
	if (ForwardValue || RightValue)
	{
		MainPlayer->IsMoving = 1;
	}
	else
	{
		MainPlayer->IsMoving = 0;
	}

}
void AMainController::MoveRight(float value)
{
	RightValue = value;
	if (value != 0)
	{
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);//��ȡY��
		MainPlayer->AddMovementInput(Direction, value);//��

	}
	if (ForwardValue || RightValue)
	{
		MainPlayer->IsMoving = 1;
	}
	else
	{
		MainPlayer->IsMoving = 0;
	}
}
void AMainController::Run()
{

}
void AMainController::StopRun()
{
	
}
void AMainController::Jump()
{
	bool IsFalling = MainPlayer->GetCharacterMovement()->IsFalling();
	//��ֹ�ڿ��м������ո��ظ�����
	if (!IsFalling)
	{
		MainPlayer->AnimPlay(MainPlayer->role_Jump);
	}

	MainPlayer->Jump();
}
void AMainController::StopJumping()
{
	MainPlayer->StopJumping();
}
/*
void AMainController::Crouch()
{

}
void AMainController::StopCrouch()
{

}
void AMainController::Lie()
{

}
void AMainController::StopLie()
{

}*/