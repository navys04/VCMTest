// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPayload.h"

#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "VCMTest/VCMDataTypes.h"

void UHealthPayload::Init()
{
	HealthMessage = FMessageEndpoint::Builder("HealthEndpoint").Handling<FHealthChangedMessage>(this, &ThisClass::HandleHealthChanged);
	HealthMessage->Subscribe<FHealthChangedMessage>();
}

void UHealthPayload::BeginDestroy()
{
	UObject::BeginDestroy();

	HealthMessage.Reset();
}

void UHealthPayload::HandleHealthChanged(const FHealthChangedMessage& Message,
                                         const TSharedRef<IMessageContext>& MessageContext)
{
	OnHealthChanged.Broadcast(Message.Health);
}
