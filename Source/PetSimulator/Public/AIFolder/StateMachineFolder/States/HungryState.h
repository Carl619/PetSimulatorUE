// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../State.h"
#include "HungryState.generated.h"

class APet;
class AAStar;
class AANode;
UCLASS()
class PETSIMULATOR_API AHungryState : public AState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHungryState();
	UPROPERTY()
	APet* Pet;
	float speed;
	AAStar* Stasr;
	TArray<AANode*> Nodes;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Execute(float DeltaTime) override;
	virtual void Init() override;
};
