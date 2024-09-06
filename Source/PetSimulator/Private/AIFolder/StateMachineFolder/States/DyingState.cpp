// Fill out your copyright notice in the Description page of Project Settings.

#include "AIFolder/StateMachineFolder/States/DyingState.h"
#include "Entities/Pet.h"


// Sets default values
ADyingState::ADyingState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADyingState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADyingState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADyingState::Execute(float DeltaTime)
{
	if (Pet->Hunger->Eating)
	{
		Pet->Health->LosingHealth(DeltaTime);
	}
	Pet->LookingForFood(DeltaTime);
}

void ADyingState::Init()
{
}