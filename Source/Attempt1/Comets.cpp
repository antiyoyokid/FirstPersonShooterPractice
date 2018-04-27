

#include "Comets.h"



// Sets default values
AComets::AComets()
{
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Rock = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComet"));
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Shape Created"));
	
	Sphere->SetSphereRadius(50);
	
	
	Sphere->AttachToComponent(Rock, FAttachmentTransformRules::SnapToTargetIncludingScale);

	Sphere->bGenerateOverlapEvents = true;
	

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/EngineMeshes/Sphere'"));
	if (MeshAsset.Object != nullptr)
	{
		Rock->SetStaticMesh(MeshAsset.Object);
	}
	
	
}

// Called when the game starts or when spawned
void AComets::BeginPlay()
{
	/*
	Super::BeginPlay();
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<AComets>(Location, Rotation, SpawnInfo);
	*/
}

// Called every frame
void AComets::Tick(float DeltaTime)
{
/*
	float randY = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX))*1000;
	float randZ = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;
	float randX = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 1000;
	Super::Tick(DeltaTime);
	FVector newLocation = GetActorLocation();
	float deltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	newLocation.Y += deltaHeight * randY;
	newLocation.Z += deltaHeight * randZ;
	newLocation.X += deltaHeight * randX;
	RunningTime += DeltaTime;
	SetActorLocation(newLocation);
	*/
	}

void AComets::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	
}






