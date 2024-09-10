// Fill out your copyright notice in the Description page of Project Settings.

#include "Entities/Pet.h"
#include "Entities/Food.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APet::APet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AI = CreateDefaultSubobject<UAIComponent>(TEXT("AI"));
	Health = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
	Social = CreateDefaultSubobject<USocialComponent>(TEXT("Social"));
	Hunger = CreateDefaultSubobject<UHungerComponent>(TEXT("Hunger"));
}

// Called when the game starts or when spawned
void APet::BeginPlay()
{
	Super::BeginPlay();
	
	Initialized = false;
}

// Called every frame
void APet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Initialized)
	{
		SetEvents();
	}

	Death();

	if (Hunger->Dying || Social->Dying)
	{
		DyingEvent.Execute();
	}
	else if (Hunger->Hungry || Social->Bored)
	{
		HungryEvent.Execute();
	}
	else if (!Hunger->Hungry && !Social->Bored)
	{
		FineEvent.Execute();
	}
}

void APet::SetEvents()
{
	if (AI != nullptr)
	{

		DyingEvent.BindUObject(AI->Machine, &AStateMachine::OnDying);
		EatingEvent.BindUObject(AI->Machine, &AStateMachine::OnHungry);
		FineEvent.BindUObject(AI->Machine, &AStateMachine::OnFine);
		HungryEvent.BindUObject(AI->Machine, &AStateMachine::OnHungry);
	}

	Initialized = true;
}

void APet::Death()
{
}

void APet::Cure(float heal)
{
	Health->AddHealth(heal);
}

void APet::Move(float speed, float DeltaTime)
{
	FRotator lookRotation;
	FVector direction;
	FVector NewLocation;
	float step = speed * DeltaTime;
	direction = (Foods[0]->GetTransform().GetLocation() - GetTransform().GetLocation());
	direction.Normalize();
	lookRotation = UKismetMathLibrary::FindLookAtRotation(GetTransform().GetLocation(), Foods[0]->GetTransform().GetLocation());
	NewLocation = FMath::Lerp(GetTransform().GetLocation(), Foods[0]->GetTransform().GetLocation(), step);
	FQuat NewRotation = FQuat::Slerp(GetTransform().GetRotation(), lookRotation.Quaternion(), DeltaTime * speed);
	SetActorLocationAndRotation(NewLocation, NewRotation, false, 0, ETeleportType::None);
}

void APet::LookingForFood(float DeltaTime)
{
	if (Foods.Num() == 0)
	{
		Hunger->Eating = false;
		Health->Healing = false;
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFood::StaticClass(), FoundActors);
		Foods.Add((AFood*)FoundActors[0]);
	}

	if (Foods.Num() > 0)
	{
		Move(5, DeltaTime);
		float distanceBetweenObjects = FVector::Dist(GetTransform().GetLocation(), Foods[0]->GetTransform().GetLocation());
		if (distanceBetweenObjects < 1)
		{
			Eat();
		}
	}
}

void APet::Eat()
{
	Hunger->Eating = true;
	Health->Healing = true;
}