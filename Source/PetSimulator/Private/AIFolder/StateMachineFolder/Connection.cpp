// Fill out your copyright notice in the Description page of Project Settings.


#include "AIFolder/StateMachineFolder/Connection.h"
#include "AIFolder/StateMachineFolder/State.h"

// Sets default values
AConnection::AConnection()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AConnection::Init(AState * end)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EndState = end;
}

// Called when the game starts or when spawned
void AConnection::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConnection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

