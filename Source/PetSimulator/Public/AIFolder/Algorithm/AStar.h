// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AStar.generated.h"

class AANode;
class AAEdge;

UCLASS()
class PETSIMULATOR_API AAStar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAStar();

	TArray<AANode*> Nodes;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	TArray<AANode*> Reconstruct(int current, int start, AANode* currentNode, TMap<int, AANode*> cameFrom);
	TArray<AANode*> Search(int start, int goal);
	AANode* LowestFvalue(TMap<int, AANode*> nodes);
	int NearestNodeID(FVector location);
	TArray<AANode*> ReverseList(TArray<AANode*> nodes);
	void Restart();
	void CalculateH(int goal);
};
