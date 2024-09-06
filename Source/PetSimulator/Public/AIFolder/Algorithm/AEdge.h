// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AEdge.generated.h"

class AANode;
UCLASS()
class PETSIMULATOR_API AAEdge : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAEdge();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AANode* NodeEnd;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Cost;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
