// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/HungerComponent.h"

// Sets default values for this component's properties
UHungerComponent::UHungerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    Hunger = 0;
    PercentAdded = 5;

    Cooldown = 0;
    CooldownMax = 5;

    Hungry = false;
    Dying = false;
    Eating = false;
}


// Called when the game starts
void UHungerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHungerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    Cooldown += DeltaTime;
    if (Cooldown >= CooldownMax)
    {

        if (Eating)
        {
            Eat();
        }
        else
        {
            HungerLoop();
        }
        Cooldown = 0;
    }
    if (!Hungry)
    {
        Eating = false;
    }

    if (Hunger == HungerMax)
    {
        Dying = true;
    }
    else if (Hunger > 80)
    {
        Hungry = true;
    }
    else if (Hunger < 20)
    {
        Hungry = false;
    }
    else if (Hunger < 50)
    {
        Dying = false;
    }
}

void UHungerComponent::HungerLoop()
{
	Hunger += PercentAdded;

	if (Hunger > HungerMax)
	{
		Hunger = HungerMax;
	}
}

void UHungerComponent::Eat()
{
	Hunger -= PercentAdded;

	if (Hunger < 0)
	{
		Hunger = 0;
	}
}

