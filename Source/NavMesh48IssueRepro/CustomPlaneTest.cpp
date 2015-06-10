// Fill out your copyright notice in the Description page of Project Settings.

#include "NavMesh48IssueRepro.h"
#include "CustomPlaneTest.h"
#include "../Plugins/Runtime/ProceduralMeshComponent/Source/ProceduralMeshComponent/Public/ProceduralMeshComponent.h"


// Sets default values
ACustomPlaneTest::ACustomPlaneTest(const FObjectInitializer& oi) : Super(oi)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProceduralMesh = oi.CreateDefaultSubobject<UProceduralMeshComponent>(this, TEXT("Mesh"));
	check(ProceduralMesh);
	RootComponent = ProceduralMesh;
	check(RootComponent);
	ProceduralMesh->SetMobility(EComponentMobility::Stationary);

	
}

// Called when the game starts or when spawned
void ACustomPlaneTest::BeginPlay()
{
	Super::BeginPlay();

	TArray<FVector> vertices;
	TArray<FVector> normals;
	TArray<FVector2D> texCoords;
	TArray<FColor> colors;
	TArray<FProcMeshTangent> tangents;
	TArray<int32> indices;

	const float SIZE = 4000;

	// 1  0
	// 
	// 3  2
	vertices.Add(FVector(SIZE, SIZE, 0));
	vertices.Add(FVector(-SIZE, SIZE, 0));
	vertices.Add(FVector(SIZE, -SIZE, 0));
	vertices.Add(FVector(-SIZE, -SIZE, 0));

	// top
	indices.Add(1);
	indices.Add(2);
	indices.Add(3);
	indices.Add(1);
	indices.Add(0);
	indices.Add(2);

	ProceduralMesh->CreateMeshSection(0, vertices, indices, normals, texCoords, colors, TArray<FProcMeshTangent>(), true);

	//ProceduralMesh->UpdateBounds();

	//RootComponent->SetWorldScale3D(FVector(1.0001f, 1.0001f, 1.0001f));
	//RootComponent->SetWorldScale3D(FVector(1.f, 1.f, 1.f));

	//UNavigationSystem::UpdateNavOctree(ProceduralMesh);
}

// Called every frame
void ACustomPlaneTest::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	

	//RootComponent->SetScale3D(FVector(1.1f, 1.1f, 1.1f));
}

