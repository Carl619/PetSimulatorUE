// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/Grid.h"
#include "AIFolder/Algorithm/AEdge.h"


// Sets default values
AGrid::AGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	Nodes = TArray<AANode*>();
}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
	Super::BeginPlay();
	MakeConnectionBetweenNodes();
}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrid::MakeConnectionBetweenNodes()
{
	for (int i = 0; i < SizeX; i++)
	{
		for (int j = 0; j < SizeY; j++)
		{
			if (i > 0)
			{
				AAEdge* edge = NewObject<AAEdge>(this, AAEdge::StaticClass());
				edge->NodeEnd = Nodes2[i-1].Nodes[j];
				Nodes2[i].Nodes[j]->Edges.Add(edge);
			}

			if (i < SizeX-1)
			{
				AAEdge* edge = NewObject<AAEdge>(this, AAEdge::StaticClass());
				edge->NodeEnd = Nodes2[i+1].Nodes[j];
				Nodes2[i].Nodes[j]->Edges.Add(edge);
			}

			if (j > 0)
			{
				AAEdge* edge = NewObject<AAEdge>(this, AAEdge::StaticClass());
				edge->NodeEnd = Nodes2[i].Nodes[j-1];
				Nodes2[i].Nodes[j]->Edges.Add(edge);
			}

			if (j < SizeY - 1)
			{
				AAEdge* edge = NewObject<AAEdge>(this, AAEdge::StaticClass());
				edge->NodeEnd = Nodes2[i].Nodes[j+1];
				Nodes2[i].Nodes[j]->Edges.Add(edge);
			}
		}
	}
}
