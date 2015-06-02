// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CustomPlaneTest.generated.h"

UCLASS()
class NAVMESH48ISSUEREPRO_API ACustomPlaneTest : public AActor
{
	GENERATED_UCLASS_BODY()
	
public:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	class UProceduralMeshComponent* ProceduralMesh;
	
};
