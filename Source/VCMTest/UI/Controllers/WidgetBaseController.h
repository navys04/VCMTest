// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WidgetBaseController.generated.h"

USTRUCT(Blueprintable)
struct FWidgetControllerData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Widget Controller Data")
	TMap<TSubclassOf<UObject>, TObjectPtr<UObject>> PropertyContainer;
};

UCLASS(Blueprintable, BlueprintType)
class VCMTEST_API UWidgetBaseController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Widget Base Controller")
	virtual void InitController(const FWidgetControllerData& InWidgetControllerData);

	virtual void BroadcastInitialData() const;

	template<typename T = UObject>
	T* GetObject(TSubclassOf<UObject> InClass = T::StaticClass())
	{
		if (WidgetControllerData.PropertyContainer.Contains(InClass))
		{
			return Cast<T>(WidgetControllerData.PropertyContainer[InClass]);
		}

		return nullptr;
	}
	
private:
	FWidgetControllerData WidgetControllerData;
};
