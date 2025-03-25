// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBaseController.h"
#include "HealthWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedInControllerSignature, const float&, Health);

UCLASS()
class VCMTEST_API UHealthWidgetController : public UWidgetBaseController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, Category = "Health Widget Controller")
	FOnHealthChangedInControllerSignature HealthChangedDelegate;
	
protected:
	virtual void InitController(const FWidgetControllerData& InWidgetControllerData) override;

private:
	UFUNCTION()
	virtual void OnHealthChanged(const float& Health);
};
