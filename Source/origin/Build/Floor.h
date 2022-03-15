// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "UObject/UObjectGlobals.h"

#include "Floor.generated.h"

UCLASS()

class ORIGIN_API AFloor : public AActor
{
	GENERATED_BODY()

public:
	AFloor();

protected:
	virtual void BeginPlay()override;

public:
	virtual void Tick(float DeltalTime)override;

	UPROPERTY(EditInstanceOnly, Category = "BaseConfig");
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditInstanceOnly, Category = "BaseConfig");
	UBoxComponent* BoxComponent;//��ײ���

	UPROPERTY(EditInstanceOnly, Category = "BaseConfig");
	float HalfXY = 200;

	UPROPERTY(EditInstanceOnly, Category = "BaseConfig");
	float HalfZ = 30;

	UPROPERTY(EditInstanceOnly, Category = "BaseConfig");
	float XYZScale = 50;//ģ����UE�������

	UPROPERTY(EditInstanceOnly, Category = "BaseConfig");
	bool IsBlock = false;

	UPROPERTY(EditInstanceOnly, Category = "BaseConfig");
	FString BlockActorName;

	void SetCollision(ECollisionEnabled::Type Type = ECollisionEnabled::NoCollision);

	void SetMaterial(FString Value);

	UFUNCTION()//�ص�������Ҫ�������
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBody);

	UFUNCTION()//�ص�������Ҫ�������
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBody);

};