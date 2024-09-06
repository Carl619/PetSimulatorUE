// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/Food.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Durability = 100;
	Cooldown = 0;
	CooldownMax = 3;
}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Cooldown += DeltaTime;
	if (Cooldown >= CooldownMax)
	{
		Durability -= 5;
		if (Durability <= 0)
		{
			Destroy();
		}
		Cooldown = 0;
	}
}

