// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "mainCharacter.h"
#include "origin/origin_Lib.h"
#include "MainController.generated.h"

/**
 * 
 */
UCLASS()
class ORIGIN_API AMainController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AMainController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;
	//检测第一/三人称
	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	bool isFirstView = false;

	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	bool CanIdle = true;

	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	bool CanRun = true;

	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	bool CanJump = true;

	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	bool CanCrouch = true;

	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	bool CanLie = true;
	


	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
  	AmainCharacter* MainPlayer;//获取当前角色

	//角色向前向右的速度值
	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	float ForwardValue;
	UPROPERTY(EditInstanceOnly, Category = "Basic Config");
	float RightValue;

private:
	void Construct();//构造函数

	//按键方法
	//Mouse
	void MouseWheelUp();
	void MouseWheelDown();
	void MouseBtnLeft();
	void MouseBtnRight();
	void MouseBtnMiddle();

	//Key or Inventory
	void KeyOne();
	void ChangeView();
	
	//Character's action
	void MoveForward(float value);
	void MoveRight(float value);
	void Run();
	void StopRun();
	void Jump();
	void StopJumping();
	void Crouch();
	void StopCrouch();
	void Lie();
	void StopLie();
	void AnimSwitch();
};
