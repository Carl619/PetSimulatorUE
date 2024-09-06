// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "State.h"
#include "States/WanderState.h"
#include "States/HungryState.h"
#include "States/DyingState.h"
#include "StateMachine.generated.h"

DECLARE_DELEGATE(FMachineStates);

UCLASS()
class PETSIMULATOR_API AStateMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStateMachine();
	TArray<AState*> States;
	UPROPERTY()
	AState* CurrentState;
	AActor* AIActor;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Execute(float DeltaTime);
	UFUNCTION()
	void OnDying();
	UFUNCTION()
	void OnHungry();
	UFUNCTION()
	void OnFine();
	void Init();
};
