// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"
#include "VCMTest/UI/Controllers/WidgetBaseController.h"
#include "VCMTest/UI/Widgets/UserBaseWidget.h"

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();
	
	InitHUD();
}

UWidgetBaseController* AMainHUD::CreateWidgetController() const
{
	return NewObject<UWidgetBaseController>();
}

void AMainHUD::InitHUD()
{
	WidgetBaseController = CreateWidgetController();
	if (!IsValid(WidgetBaseController)) return;

	MainWidget = CreateWidget<UUserBaseWidget>(GetWorld(), MainWidgetClass);
	if (!IsValid(MainWidget)) return;

	MainWidget->SetupWidgetController(WidgetBaseController);
	MainWidget->AddToViewport();
}

