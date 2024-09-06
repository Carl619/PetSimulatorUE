// Fill out your copyright notice in the Description page of Project Settings.


#include "AIFolder/Algorithm/AStar.h"
#include "AIFolder/Algorithm/ANode.h"
#include "AIFolder/Algorithm/AEdge.h"
#include "Algo/Reverse.h"

// Sets default values
AAStar::AAStar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Nodes = TArray<AANode*>();
}

// Called when the game starts or when spawned
void AAStar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<AANode*> AAStar::Reconstruct(int current, int start, AANode* currentNode, TMap<int, AANode*> cameFrom)
{
    TArray<AANode*> path = TArray<AANode*>();

    path.Add(currentNode);



    while (current != start)

    {

        path.Add(cameFrom[current]);

        current = cameFrom[current]->ID;

    }
    return ReverseList(path);
}

TArray<AANode*> AAStar::Search(int start, int goal)
{
    TMap<int, AANode*> openSet = TMap<int, AANode*>();

    TMap<int, AANode*> closeSet = TMap<int, AANode*>();

    TMap<int, AANode*> cameFrom = TMap<int, AANode*>();



    Nodes[start]->GValue = 0;

    Nodes[start]->FValue = Nodes[start]->HValue;



    openSet.Add(Nodes[start]->ID, Nodes[start]);



    while (!openSet.IsEmpty())

    {

        AANode* current = LowestFvalue(openSet);

        if (current == Nodes[goal])

        {

            return Reconstruct(current->ID, start, current, cameFrom);

        }



        openSet.Remove(current->ID);

        for (int i = 0; i < current->Edges.Num(); i++)

        {

            if (closeSet.Find(current->Edges[i]->NodeEnd->ID) == nullptr)

            {

                float tentativeGScore = current->GValue + current->Edges[i]->Cost;

                if (tentativeGScore < current->Edges[i]->NodeEnd->GValue)

                {

                    if (cameFrom.Find(current->Edges[i]->NodeEnd->ID) != nullptr)

                    {

                        cameFrom[current->Edges[i]->NodeEnd->ID] = current;

                    }

                    else {

                        cameFrom.Add(current->Edges[i]->NodeEnd->ID, current);

                    }

                    if (openSet.Find(current->Edges[i]->NodeEnd->ID) == nullptr)

                    {

                        current->Edges[i]->NodeEnd->GValue = tentativeGScore;

                        current->Edges[i]->NodeEnd->FValue = tentativeGScore + current->Edges[i]->NodeEnd->HValue;

                        openSet.Add(current->Edges[i]->NodeEnd->ID, current->Edges[i]->NodeEnd);

                        closeSet.Add(current->ID, current);

                    }

                    else

                    {

                        if (tentativeGScore < current->Edges[i]->NodeEnd->GValue)

                        {

                            current->Edges[i]->NodeEnd->GValue = tentativeGScore;

                            current->Edges[i]->NodeEnd->FValue = tentativeGScore + current->Edges[i]->NodeEnd->HValue;

                            cameFrom.Add(current->Edges[i]->NodeEnd->ID, current);

                        }

                    }

                }

            }

        }
    }
    
	return TArray<AANode*>();
}

AANode* AAStar::LowestFvalue(TMap<int, AANode*> nodes)
{
    float fValue = -1;
    AANode* node = nullptr;
    for (const TPair<int, AANode*>& pair : nodes)
    {
        if (fValue == -1)
        {
            node = pair.Value;
        }
        if (pair.Value->FValue < node->FValue)
        {
            node = pair.Value;
        }
    }
    return node;
}

int AAStar::NearestNodeID(FVector location)
{
    FVector nearestLocation = Nodes[0]->GetActorLocation();
    int node = 0;
    for (int i = 0; i < Nodes.Num(); i++)
    {
        if (FVector::Dist(nearestLocation, location) > FVector::Dist(Nodes[i]->GetActorLocation(), location))
        {
            nearestLocation = Nodes[i]->GetActorLocation();
            node = i;
        }
    }
    return node;
}

TArray<AANode*> AAStar::ReverseList(TArray<AANode*> nodes)
{
    Algo::Reverse(nodes);
    return nodes;
}

void AAStar::Restart()
{
    for (int i = 0; i < Nodes.Num(); i++)
    {
        Nodes[i]->FValue = 0;
        Nodes[i]->GValue = 0;
    }
}

void AAStar::CalculateH(int goal)
{
    for (int i = 0; i < Nodes.Num(); i++)
    {
        if (i != goal)
        {
            Nodes[i]->HValue = FVector::Dist(Nodes[i]->GetActorLocation(), Nodes[goal]->GetActorLocation());
        }
    }
}

