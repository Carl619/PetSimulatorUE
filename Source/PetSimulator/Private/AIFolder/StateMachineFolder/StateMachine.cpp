// Fill out your copyright notice in the Description page of Project Settings.


#include "AIFolder/StateMachineFolder/StateMachine.h"

// Sets default values
AStateMachine::AStateMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
}

// Called when the game starts or when spawned
void AStateMachine::BeginPlay()
{
	Super::BeginPlay();
	States = TArray<AState*>();
}

// Called every frame
void AStateMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStateMachine::Init()
{
    FActorSpawnParameters SpawnParams = FActorSpawnParameters();
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
    AWanderState* wander = AIActor->GetWorld()->SpawnActor<AWanderState>(SpawnParams);
    AHungryState* hungry = AIActor->GetWorld()->SpawnActor<AHungryState>(SpawnParams);
    ADyingState* dying = AIActor->GetWorld()->SpawnActor<ADyingState>(SpawnParams);

    wander->AIActor = AIActor;
    hungry->AIActor = AIActor;
    dying->AIActor = AIActor;
    
    wander->Init();
    hungry->Init();
    dying->Init();
    AConnection* con = AIActor->GetWorld()->SpawnActor<AConnection>(FVector(0,0,0), FRotator(0.0f, 0.0f, 0.0f));
    con->Init(hungry);
    wander->Connections.Add("hungry", con);
    con = AIActor->GetWorld()->SpawnActor<AConnection>(FVector(0, 0, 0), FRotator(0.0f, 0.0f, 0.0f));
    con->Init(wander);
    hungry->Connections.Add("fine", con);
    con = AIActor->GetWorld()->SpawnActor<AConnection>(FVector(0, 0, 0), FRotator(0.0f, 0.0f, 0.0f));
    con->Init(dying);
    hungry->Connections.Add("dying", con);
    con = AIActor->GetWorld()->SpawnActor<AConnection>(FVector(0, 0, 0), FRotator(0.0f, 0.0f, 0.0f));
    con->Init(wander);
    dying->Connections.Add("fine", con);

    States.Add(wander);
    States.Add(hungry);
    States.Add(dying);

    CurrentState = States[0];
}

void AStateMachine::Execute(float DeltaTime)
{
    CurrentState->Execute(DeltaTime);
}

void AStateMachine::OnDying()
{
    if (CurrentState->Connections.Contains("hungry"))
    {
        CurrentState = CurrentState->Connections["hungry"]->EndState;
    }
}

void AStateMachine::OnHungry()
{
    if (CurrentState->Connections.Contains("dying"))
    {
        CurrentState = CurrentState->Connections["dying"]->EndState;
    }
}

void AStateMachine::OnFine()
{
    if (CurrentState->Connections.Contains("fine"))
    {
        CurrentState = CurrentState->Connections["fine"]->EndState;
    }
}
