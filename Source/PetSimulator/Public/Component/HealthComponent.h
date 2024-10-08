// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PETSIMULATOR_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Health;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HealthMax;
	float PercentLost;

	float Cooldown;
	float CooldownMax;

	bool Dying;
	bool Healing;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void LosingHealth(float DeltaTime);
	void AddHealth(float heal);
	void Cure();
};
