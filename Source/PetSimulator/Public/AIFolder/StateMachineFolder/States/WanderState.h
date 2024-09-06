// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../State.h"
#include "Math/Quat.h"
#include "Kismet/KismetMathLibrary.h"
#include "WanderState.generated.h"

class AGrid;
class AAStar;
class AANode;

UCLASS()
class PETSIMULATOR_API AWanderState : public AState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWanderState();
	float speed;
	FVector Target;
	int mul;

	float Cooldown;
	float Cooldownmax;

	AGrid* Grid;
private: 
	FQuat LookRotation;
	FVector Direction;
	AAStar* Star;
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
