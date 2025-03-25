// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HealthPayload.generated.h"

class IMessageContext;
struct FHealthChangedMessage;
class FMessageEndpoint;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthChangedSignature, const float&, NewHealth);

UCLASS(Blueprintable, BlueprintType)
class VCMTEST_API UHealthPayload : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Init();
	
	FORCEINLINE FHealthChangedSignature* GetHealthChangedDelegate() { return &OnHealthChanged; }
	
protected:
	UPROPERTY(BlueprintAssignable, Category = "Health Payload")
	FHealthChangedSignature OnHealthChanged;

	virtual void BeginDestroy() override;
	
private:
	void HandleHealthChanged(const FHealthChangedMessage& Message, const TSharedRef<IMessageContext>& MessageContext);
	TSharedPtr<FMessageEndpoint> HealthMessage;
};
