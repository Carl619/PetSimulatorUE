// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HungerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PETSIMULATOR_API UHungerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHungerComponent();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Hunger;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HungerMax = 100;
	float PercentAdded;

	float Cooldown;
	float CooldownMax;

	bool Hungry;
	bool Dying;
	bool Eating;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void HungerLoop();
	void Eat();
		
};
