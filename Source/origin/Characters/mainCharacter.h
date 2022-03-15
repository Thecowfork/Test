// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "UObject/ObjectMacros.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "mainCharacter.generated.h"//this header must be the last
UCLASS()
class ORIGIN_API AmainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AmainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//骨骼模型
	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	USkeletalMesh* SkeletalMesh;
	

	//相机摇臂
	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	USpringArmComponent* SpringArmComponent;

	//Camera
	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	UCameraComponent* CameraComponent;

	//检测角色是否移动
	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	bool IsMoving = false;

	UAnimSequence* AnimSeq;//AnimSequence
	//待机动画Idle
	FString role_Idle = TEXT("AnimSequence'/Game/_origin/Characters/default/Animations/ThirdPersonIdle.ThirdPersonIdle'");
	//Walk
	FString role_Walk = TEXT("AnimSequence'/Game/_origin/Characters/default/Animations/ThirdPersonWalk.ThirdPersonWalk'");
	//Run
	FString role_Run = TEXT("AnimSequence'/Game/_origin/Characters/default/Animations/ThirdPersonRun.ThirdPersonRun'");
	//Jump
	FString role_Jump = TEXT("AnimSequence'/Game/_origin/Characters/default/Animations/ThirdPersonJump_Start.ThirdPersonJump_Start'");
	FString role_JumpLoop = TEXT("AnimSequence'/Game/_origin/Characters/default/Animations/ThirdPersonJump_Loop.ThirdPersonJump_Loop'");
	//Crouch 

	//Lie



	//摄像机视角设置
	void FirstPerson();//第一人称
	void ThirdPerson();//第三人称

	//
	void AnimPlay(FString Value, bool loop = false);

	FString GetPlayingAnimName();




private:
	void Construct();//
	void CreateModel();
	
};
