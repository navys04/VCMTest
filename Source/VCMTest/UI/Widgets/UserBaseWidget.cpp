// Fill out your copyright notice in the Description page of Project Settings.


#include "UserBaseWidget.h"

#include "VCMTest/UI/Controllers/WidgetBaseController.h"

void UUserBaseWidget::SetupWidgetController(const UWidgetBaseController* InController)
{
	WidgetController = InController;
	if (!IsValid(WidgetController)) return;

	OnWidgetControllerSettedUp(InController);
	WidgetController->BroadcastInitialData();
}
