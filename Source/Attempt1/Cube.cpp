

#include "Cube.h"


// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
			
	// Sets settings for the Cube Object
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
	
	Super::Tick(DeltaTime);
	FVector newLocation = GetActorLocation(); // Gets cube current location
	
	float deltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime)); // Makes cube fly back and forth
	int ExtraSpeed = RunningTime * RunningTimeMultiplier; // More ExtraSpeed based on time
	
	if (ExtraSpeed < MaxExtraSpeed) {
		if (movementY) {
			newLocation.Y += deltaHeight * (cubeSpeed + ExtraSpeed); // Makes speed of object go faster over time
		}
		else if (movementX){
			newLocation.X += deltaHeight * (cubeSpeed + ExtraSpeed);
		}
		else if (movementZ){
			newLocation.Z += deltaHeight * (cubeSpeed + ExtraSpeed);
		}
	}
	RunningTime += DeltaTime;
	SetActorLocation(newLocation);

}

