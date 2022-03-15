// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Characters/mainCharacter.h"
#include "BuildSystem.generated.h"

UCLASS(classGroup = (Custom), meta = (BlueprintSpawnableComponent))

class ORIGIN_API UBuildSystem :public UActorComponent
{
	GENERATED_BODY()
public:
	UBuildSystem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)override;
	AmainCharacter* MainPlayer;
	float BuildDistance = 500;
	FVector BuildLocation;
	UObject* BuildItem = nullptr;
};
