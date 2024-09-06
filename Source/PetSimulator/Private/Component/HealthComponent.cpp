// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	HealthMax = 100;
	Health = 80;
	PercentLost = 5;

	Dying = false;

	Cooldown = 0;
	CooldownMax = 5;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Cooldown += DeltaTime;
	if (Cooldown >= CooldownMax)
	{
		if (Healing)
		{
			Cure();
		}
		Cooldown = 0;
	}
}

void UHealthComponent::LosingHealth(float DeltaTime)
{
	Cooldown += DeltaTime;
	if (Cooldown >= CooldownMax)
	{
		Health -= PercentLost;

		if (Health < 0)
		{
			Health = 0;
		}
		Cooldown = 0;
	}
}

void UHealthComponent::AddHealth(float heal)
{
	Health += heal;

	if (Health > HealthMax)
	{
		Health = HealthMax;
	}
}
void UHealthComponent::Cure()
{
	Health += PercentLost;

	if (Health > HealthMax)
	{
		Health = HealthMax;
	}
}

