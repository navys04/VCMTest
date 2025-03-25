// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetBaseController.h"

void UWidgetBaseController::InitController(const FWidgetControllerData& InWidgetControllerData)
{
	WidgetControllerData = InWidgetControllerData;
}

void UWidgetBaseController::BroadcastInitialData() const
{
}
