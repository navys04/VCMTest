// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthWidgetController.h"

#include "VCMTest/UI/Payloads/HealthPayload.h"

void UHealthWidgetController::InitController(const FWidgetControllerData& InWidgetControllerData)
{
	Super::InitController(InWidgetControllerData);

	if (UHealthPayload* HealthPayload = GetObject<UHealthPayload>())
	{
		HealthPayload->GetHealthChangedDelegate()->AddUniqueDynamic(this, &ThisClass::OnHealthChanged);
	}
	
}

void UHealthWidgetController::OnHealthChanged(const float& Health)
{
	HealthChangedDelegate.Broadcast(Health);
}