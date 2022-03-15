// Fill out your copyright notice in the Description page of Project Settings.


#include "mainCharacter.h"
#include "Components/CapsuleComponent.h"
// Sets default values
AmainCharacter::AmainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->Construct();
	this->CreateModel();
	this->ThirdPerson();
	AutoPossessPlayer = EAutoReceiveInput::Player0;//������ϷĬ�Ͽ������0

}
void AmainCharacter::Construct()
{
	//����������SkeletalMesh
	SkeletalMesh = LoadObject<USkeletalMesh>(NULL,
		TEXT("SkeletalMesh'/Game/_origin/Characters/default/Mesh/SK_Mannequin_Female.SK_Mannequin_Female'"));

	//Camera Arm
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComeponent"));

	//CameraComponent
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->JumpZVelocity = 1200;
	GetCharacterMovement()->AirControl = 1;
	GetCharacterMovement()->GravityScale = 10;


}

void AmainCharacter::CreateModel()
{
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetMesh()->SetRelativeLocation(FVector(0, 0, -100));
	GetMesh()->SetSkeletalMesh(SkeletalMesh);
	GetCapsuleComponent()->InitCapsuleSize(42, 100);
	
}

// Called when the game starts or when spawned
void AmainCharacter::BeginPlay()
{
	Super::BeginPlay();
	this->AnimPlay(role_Idle, true); 
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;//�����Ƿ�����¶�
	SpringArmComponent->TargetArmLength = 400;//���ñ۳�
}

// Called every frame
void AmainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AmainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("LookRight", this, &AmainCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookForward", this, &AmainCharacter::AddControllerPitchInput);

}
void AmainCharacter::FirstPerson()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;
	SpringArmComponent->SetupAttachment(GetMesh()); //�����������λ��
	SpringArmComponent->SetRelativeLocation(FVector(-2.5, -10, 140)); //����ҡ�����λ��
	SpringArmComponent->SetRelativeRotation(FRotator(0, 90, 0)); //�������ҡ����б��x��-15
	SpringArmComponent->bUsePawnControlRotation = true; //�ý�ɫ������������ת


}
void AmainCharacter::ThirdPerson()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false; 
	GetCharacterMovement()->RotationRate = FRotator(0, 540, 0); //�������λ��
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetRelativeLocation(FVector(0, 0, 100)); //����ҡ�����λ��
	SpringArmComponent->SetRelativeRotation(FRotator(-15, 0, 0)); //�������ҡ����б��x��-15
	SpringArmComponent->bUsePawnControlRotation = true;
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->SetRelativeLocation(FVector::ZeroVector);
	CameraComponent->bUsePawnControlRotation = false;

}

void  AmainCharacter::AnimPlay(FString Value, bool loop )
{
	AnimSeq = LoadObject<UAnimSequence>(NULL, *Value);
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	GetMesh()->SetAnimation(AnimSeq);
	GetMesh()->Play(loop);
}

FString AmainCharacter::GetPlayingAnimName()
{
	return AnimSeq->GetPathName();
}