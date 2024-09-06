// Fill out your copyright notice in the Description page of Project Settings.

#include "AIFolder/StateMachineFolder/States/HungryState.h"
#include "Entities/Pet.h"
#include "Entities/Food.h"
#include "Entities/Grid.h"
#include "Kismet/GameplayStatics.h"
#include "AIFolder/Algorithm/AStar.h"

// Sets default values
AHungryState::AHungryState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StateAction = TEXT("Pet is bored or hungry");
	speed = 10;
}

// Called when the game starts or when spawned
void AHungryState::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHungryState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHungryState::Execute(float DeltaTime) 
{
	float step = speed * DeltaTime;
	if (Pet->Foods.Num() == 0)
	{
		Pet->Hunger->Eating = false;
		Pet->Health->Healing = false;
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(AIActor->GetWorld(), AFood::StaticClass(), FoundActors);
		Pet->Foods.Add((AFood*)FoundActors[0]);
	}

	if (Pet->Foods.Num() > 0)
	{
		if (Nodes.IsEmpty())
		{
			Star->Restart();
			Nodes = Star->Search(Star->NearestNodeID(AIActor->GetActorLocation()), Star->NearestNodeID(Pet->Foods[0]->GetActorLocation()));
		}
		while (!Nodes.IsEmpty())
		{
			FRotator RotTarget = UKismetMathLibrary::FindLookAtRotation(AIActor->GetActorLocation(), Nodes[0]->GetActorLocation());
			FQuat NewRotation = FQuat::Slerp(AIActor->GetActorQuat(), RotTarget.Quaternion(), DeltaTime * speed);
			AIActor->SetActorLocation(FMath::Lerp(AIActor->GetActorLocation(), Nodes[0]->GetActorLocation(), step));
			AIActor->SetActorRotation(NewRotation);

			if (FVector::Dist(Nodes[0]->GetActorLocation(), AIActor->GetActorLocation()) < 1)
			{
				Nodes.Pop();
			}
		}
		float distanceBetweenObjects = FVector::Dist(GetTransform().GetLocation(), Pet->Foods[0]->GetTransform().GetLocation());
		if (distanceBetweenObjects < 1)
		{
			Pet->Eat();
		}
	}
}

void AHungryState::Init()
{
	Star = NewObject<AAStar>(this, AAStar::StaticClass());
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(AIActor->GetWorld(), AGrid::StaticClass(), FoundActors);
	AGrid* grid = (AGrid*)FoundActors[0];
	for (int i = 0; i < grid->SizeX; i++)
	{
		for (int j = 0; j < grid->SizeY; j++)
		{
			Star->Nodes.Add(grid->Nodes2[i].Nodes[j]);
		}
	}
}
