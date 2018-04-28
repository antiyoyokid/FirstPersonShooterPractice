// Fill out your copyright notice in the Description page of Project Settings.

#include "Cube.h"


// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComet"));
	Cube = CreateDefaultSubobject<UBoxComponent>(TEXT("Cube Shape Created"));
	Cube->SetBoxExtent(FVector(1.0f, 1.0f, 1.0f)); // Set size of the cube
		
	Cube->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetIncludingScale);

	Cube->bGenerateOverlapEvents = true;

	// Gets the mesh from file location
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/EngineMeshes/Cube'")); 
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}


}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	Code to make cube move in random directions if required...
	float randY = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;
	float randZ = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;
	float randX = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;
	*/
	Super::Tick(DeltaTime);
	FVector newLocation = GetActorLocation(); // Gets cube current location
	
	float deltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime)); // Makes cube fly back and forth
	if (movementY) {
		newLocation.Y += deltaHeight * cubeSpeed;
	}
	else {
		newLocation.X += deltaHeight * cubeSpeed;
	}
	//newLocation.Z += deltaHeight * randZ;
	//newLocation.X += deltaHeight * randX;
	RunningTime += DeltaTime;
	SetActorLocation(newLocation);

}

