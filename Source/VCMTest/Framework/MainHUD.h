// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

class UWidgetBaseController;
class UUserBaseWidget;

UCLASS()
class VCMTEST_API AMainHUD : public AHUD
{
	GENERATED_BODY()

public:
	void InitHUD();
	
protected:
	virtual void BeginPlay() override;
	
private:
	UWidgetBaseController* CreateWidgetController() const;
	
	UPROPERTY(EditDefaultsOnly, Category = "Main HUD", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserBaseWidget> MainWidgetClass;

	UPROPERTY()
	TObjectPtr<UUserBaseWidget> MainWidget;

	UPROPERTY()
	TObjectPtr<UWidgetBaseController> WidgetBaseController;
};
