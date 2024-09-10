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
				Nodes.RemoveAt(0);
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
	
}
