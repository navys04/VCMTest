// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPayload.h"

#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"
#include "VCMTest/VCMDataTypes.h"

void UHealthPayload::Init()
{
	HealthMessage = FMessageEndpoint::Builder("HealthEndpoint").Handling<FHealthChangedMessage>(this, &ThisClass::HandleHealthChanged);
	HealthMessage->Subscribe<FHealthChangedMessage>();

	FTimerHandle Timer;
	if (GetOuter())
	{
		GetOuter()->GetWorld()->GetTimerManager().SetTimer(Timer, FTimerDelegate::CreateUObject(this, &ThisClass::TimerTick), 0.25f, true);
	}
}

void UHealthPayload::TimerTick()
{
	UE_LOG(LogTemp, Display, TEXT("Payload alive!"));
}

void UHealthPayload::HandleHealthChanged(const FHealthChangedMessage& Message,
                                         const TSharedRef<IMessageContext>& MessageContext)
{
	OnHealthChanged.Broadcast(Message.Health);
}
