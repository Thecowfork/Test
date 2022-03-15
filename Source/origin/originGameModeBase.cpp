// Copyright Epic Games, Inc. All Rights Reserved.


#include "originGameModeBase.h"

#include "Characters/MainController.h"


AoriginGameModeBase::AoriginGameModeBase()
{
	//函数作用为绑定mainCharacter和mainController
	//下面两行为绑定操作
	PlayerControllerClass = AMainController::StaticClass();
	DefaultPawnClass = AMainController::StaticClass();
}
