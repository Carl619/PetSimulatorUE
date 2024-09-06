// Fill out your copyright notice in the Description page of Project Settings.


#include "AIFolder/Algorithm/ANode.h"
#include "AIFolder/Algorithm/AEdge.h"
#include "Entities/Obstacle.h"

// Sets default values
AANode::AANode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Obstacle Cullusion"));
	Activated = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;
	SphereCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	HValue = 1;
	Cost = 1;
}

// Called when the game starts or when spawned
void AANode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AANode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AANode::SetNode(float g, float f, float h, float cost)
{
	GValue = g;
	FValue = f;
	HValue = h;
	Cost = cost;
	
	TArray<AAEdge*>();
}

void AANode::OnOverlapPlayer(UPrimitiveComponent* ThisComp,AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AObstacle* obstacle = (AObstacle*)OtherActor)
	{
		if (obstacle != nullptr)
		{
			Activated = false;
		}
	}
}
