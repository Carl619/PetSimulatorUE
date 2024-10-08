// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/AIComponent.h"
#include "AIFolder/StateMachineFolder/States/WanderState.h"
#include "AIFolder/StateMachineFolder/States/HungryState.h"
#include "AIFolder/StateMachineFolder/States/DyingState.h"
#include "Entities/Pet.h"

// Sets default values for this component's properties
UAIComponent::UAIComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Machine = CreateDefaultSubobject<AStateMachine>(TEXT("Machine"));
	
	// ...
}


// Called when the game starts
void UAIComponent::BeginPlay()
{
	Super::BeginPlay();
	Machine->AIActor = GetOwner();
	Machine->Init();
}


// Called every frame
void UAIComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Machine->Execute(DeltaTime);
}

