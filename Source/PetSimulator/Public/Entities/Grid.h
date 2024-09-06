// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIFolder/Algorithm/ANode.h"
#include "Grid.generated.h"

USTRUCT(BlueprintType)
struct FNestedArray
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AANode*> Nodes;
};

UCLASS()
class PETSIMULATOR_API AGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrid();
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	USceneComponent* SceneRoot;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AANode*> Nodes;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int SizeX;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int SizeY;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FNestedArray> Nodes2;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MakeConnectionBetweenNodes();
};
