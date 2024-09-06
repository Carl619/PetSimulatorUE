// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Connection.generated.h"

class AState;

UCLASS()
class PETSIMULATOR_API AConnection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConnection();
	UPROPERTY()
	AState * BeginState;
	UPROPERTY()
	AState * EndState;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Init(AState* end);

};
