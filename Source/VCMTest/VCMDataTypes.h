// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VCMDataTypes.generated.h"

USTRUCT()
struct FHealthChangedMessage
{
	GENERATED_BODY();

	UPROPERTY()
	float Health;

	FHealthChangedMessage() = default;
	FHealthChangedMessage(const float& InHealth) : Health(InHealth) {}
};