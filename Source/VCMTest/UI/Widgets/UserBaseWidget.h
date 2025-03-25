// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserBaseWidget.generated.h"

class UWidgetBaseController;

UCLASS()
class VCMTEST_API UUserBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Widget Controller")
	void SetupWidgetController(const UWidgetBaseController* InController);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Widget Controller")
	void OnWidgetControllerSettedUp(const UWidgetBaseController* InController);
	
private:
	UPROPERTY(BlueprintReadOnly, Category = "User Base Widget", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<const UWidgetBaseController> WidgetController;
};
