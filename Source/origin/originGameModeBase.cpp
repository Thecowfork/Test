// Copyright Epic Games, Inc. All Rights Reserved.


#include "originGameModeBase.h"

#include "Characters/MainController.h"


AoriginGameModeBase::AoriginGameModeBase()
{
	//��������Ϊ��mainCharacter��mainController
	//��������Ϊ�󶨲���
	PlayerControllerClass = AMainController::StaticClass();
	DefaultPawnClass = AMainController::StaticClass();
}
