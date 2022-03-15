// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildSystem.h"




UBuildSystem::UBuildSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBuildSystem::BeginPlay()
{
	Super::BeginPlay();
}

void UBuildSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
