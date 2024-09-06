// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SocialComponent.h"

// Sets default values for this component's properties
USocialComponent::USocialComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	HappinessMax = 100;
	Happiness = HappinessMax;
	PercentLost = 5;

	Dying = false;
	Bored = false;

	Cooldown = 0;
	CooldownMax = 5;
}


// Called when the game starts
void USocialComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USocialComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	LosingHappiness(DeltaTime);


	if (Happiness == 0)
	{
		Dying = true;
	}
	else if (Happiness > 80)
	{
		Bored = false;
	}
	else if (Happiness < 20)
	{
		Bored = true;
	}
	else if (Happiness > 50)
	{
		Dying = false;
	}
}

void USocialComponent::LosingHappiness(float DeltaTime)
{
	Cooldown += DeltaTime;
	if (Cooldown >= CooldownMax)
	{
		Happiness -= PercentLost;

		if (Happiness < 0)
		{
			Happiness = 0;
		}
		Cooldown = 0;
	}
}
void USocialComponent::AddHappiness(float heal)
{
	Happiness += heal;

	if (Happiness > HappinessMax)
	{
		Happiness = HappinessMax;
	}
}
void USocialComponent::Pet() 
{
	Happiness += PercentLost;

	if (Happiness > HappinessMax)
	{
		Happiness = HappinessMax;
	}
}

