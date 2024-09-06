// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../AIFolder/StateMachineFolder/StateMachine.h"
#include "../Component/AIComponent.h"
#include "../Component/HealthComponent.h"
#include "../Component/HungerComponent.h"
#include "../Component/SocialComponent.h"

#include "Pet.generated.h"

class AFood;

UCLASS()
class PETSIMULATOR_API APet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APet();
	FMachineStates DyingEvent;
	FMachineStates EatingEvent;
	FMachineStates HungryEvent;
	FMachineStates FineEvent;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAIComponent* AI;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UHealthComponent* Health;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USocialComponent* Social;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UHungerComponent* Hunger;
	TArray<AFood*> Foods;
	int test;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LookingForFood(float DeltaTime);
	void Death();
	void CreateFood();
	void Cure(float heal);
	void Move(float speed, float DeltaTime);
	void Eat();
private:
	bool Initialized;
	void SetEvents();
};
