// Fill out your copyright notice in the Description page of Project Settings.


#include "AIFolder/Algorithm/AEdge.h"
#include "AIFolder/Algorithm/ANode.h"
// Sets default values
AAEdge::AAEdge()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Cost = 1;
}

// Called when the game starts or when spawned
void AAEdge::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAEdge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

