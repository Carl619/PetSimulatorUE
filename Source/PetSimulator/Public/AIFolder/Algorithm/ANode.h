// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "ANode.generated.h"

class AAEdge;
class AObstacle;

UCLASS()
class PETSIMULATOR_API AANode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AANode();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AAEdge*> Edges;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float GValue;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float FValue;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float HValue;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Cost;

	bool Activated;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	USceneComponent* SceneRoot;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	USphereComponent* SphereCollision;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int ID;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetNode(float g, float f, float h, float cost);

	void OnOverlapPlayer(UPrimitiveComponent* ThisComp,AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
