// Fill out your copyright notice in the Description page of Project Settings.


#include "AIFolder/StateMachineFolder/States/WanderState.h"
#include "AIFolder/Algorithm/AStar.h"
#include "Entities/Grid.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWanderState::AWanderState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    mul = 5;
    int ran = FMath::RandRange(0, 99);
    Target = FVector(ran * mul, 0, ran * mul);
    Cooldownmax = 3;
    Cooldown = 0;
    StateAction = TEXT("Wander around the room");
    speed = 5;
}

// Called when the game starts or when spawned
void AWanderState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWanderState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWanderState::Execute(float DeltaTime)
{
    float step = speed * DeltaTime; // calculate distance to move
    Cooldown += DeltaTime;
    if (Nodes.IsEmpty())
    {
        if (Cooldown > Cooldownmax) {
            Star->Restart();
            int x = FMath::RandRange(0, 4);
            int y = FMath::RandRange(0, 4);
            int goal = x + y * 5;
            Nodes = Star->Search(Star->NearestNodeID(AIActor->GetActorLocation()), goal);
            Cooldown = 0;
        }
    }
    if (!Nodes.IsEmpty())
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
}

void AWanderState::Init()
{
}

