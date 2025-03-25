// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "VCMTest/VCMDataTypes.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	MaxHealth = 100.0f;
	CurrentHealth = 100.0f;

	HealthMessage = FMessageEndpoint::Builder("HealthEndpoint").Build();
}

void UHealthComponent::SetHealth(const float NewHealth)
{
	CurrentHealth = NewHealth;

	HealthMessage->Publish(new FHealthChangedMessage(NewHealth));
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentHealth = MaxHealth;

	SetHealth(CurrentHealth);
}

void UHealthComponent::DestroyComponent(bool bPromoteChildren)
{
	Super::DestroyComponent(bPromoteChildren);

	HealthMessage.Reset();
}