// Fill out your copyright notice in the Description page of Project Settings.


#include "AIFolder/StateMachineFolder/State.h"

// Sets default values
AState::AState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StateAction = TEXT("");
	Connections = TMap<FString, AConnection*>();
}

// Called when the game starts or when spawned
void AState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AState::Enter()
{

}

void AState::Execute(float DeltaTime)
{
}

void AState::Exit()
{

}

void AState::Init()
{

}

