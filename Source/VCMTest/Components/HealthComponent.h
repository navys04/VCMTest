// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class FMessageEndpoint;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VCMTEST_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UFUNCTION(BlueprintCallable, Category = "Health Component")
	void SetHealth(const float NewHealth);

	UFUNCTION(BlueprintPure, Category = "Health Component")
	FORCEINLINE float GetHealth() const { return CurrentHealth; };
	
protected:
	virtual void BeginPlay() override;
	virtual void DestroyComponent(bool bPromoteChildren) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health Component", meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

	float CurrentHealth;

	TSharedPtr<FMessageEndpoint> HealthMessage;
};
