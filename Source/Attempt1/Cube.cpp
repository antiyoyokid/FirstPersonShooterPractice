// Fill out your copyright notice in the Description page of Project Settings.

#include "Cube.h"


// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	Rock = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComet"));
	Cube = CreateDefaultSubobject<UBoxComponent>(TEXT("Sphere Shape Created"));
	Cube->SetBoxExtent(FVector(1, 1, 1)); 
	//probabably want to set the scale
	
	


	Cube->AttachToComponent(Rock, FAttachmentTransformRules::SnapToTargetIncludingScale);

	Cube->bGenerateOverlapEvents = true;


	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/EngineMeshes/Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		Rock->SetStaticMesh(MeshAsset.Object);
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
	
	//float randY = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;
	//float randZ = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;
	//float randX = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;
	Super::Tick(DeltaTime);
	FVector newLocation = GetActorLocation();
	
	float deltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
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

