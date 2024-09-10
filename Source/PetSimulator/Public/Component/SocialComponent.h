// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SocialComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PETSIMULATOR_API USocialComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USocialComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Happiness;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HappinessMax;
	float PercentLost;

	float Cooldown;
	float CooldownMax;

	bool Dying;
	bool Bored;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void LosingHappiness(float DeltaTime);
	void AddHappiness(float heal);
	UFUNCTION(BlueprintCallable)
	void Pet();
};
