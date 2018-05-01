

#include "Comets.h"



// Sets default values
AComets::AComets()
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComet"));
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Shape Created"));

	Sphere->SetSphereRadius(50);
	Sphere->AttachToComponent(SphereMesh, FAttachmentTransformRules::SnapToTargetIncludingScale); // Makes mesh component take the shape of Actor
	Sphere->bGenerateOverlapEvents = true;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/EngineMeshes/Sphere'"));
	if (MeshAsset.Object != nullptr)
	{
		SphereMesh->SetStaticMesh(MeshAsset.Object);
	}

}

// Called when the game starts or when spawned
void AComets::BeginPlay()
{


}

// Called every frame
void AComets::Tick(float DeltaTime)
{

	// Random x,y,z values
	float randY = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;
	float randZ = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;
	float randX = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;

	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation();

	// Movement back and forth
	float deltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	// Setters for new location
	newLocation.Y += deltaHeight * randY;
	newLocation.Z += deltaHeight * randZ;
	newLocation.X += deltaHeight * randX;

	RunningTime += DeltaTime;
	SetActorLocation(newLocation);

}







