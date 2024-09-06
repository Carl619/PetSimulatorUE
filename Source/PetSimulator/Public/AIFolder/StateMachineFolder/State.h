// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Connection.h"
#include "State.generated.h"

UCLASS()
class PETSIMULATOR_API AState : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AState();
	FString StateAction;
	TMap<FString, AConnection*> Connections;
	UPROPERTY()
	AActor* AIActor;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Enter();
	virtual void Execute(float DeltaTime);
	void Exit();
	virtual void Init();
};
