
#pragma once

#include "CoreMinimal.h"
#include "Engine.h"

#include "GameFramework/Actor.h"
#include "Comets.generated.h"




UCLASS()
class ATTEMPT1_API AComets : public AActor
{
	GENERATED_BODY() // A
	
public:	
	// Sets default values for this actor's properties
	AComets();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float RunningTime; // To track total elapsed time

	FVector playerStartPos = FVector(-1561.0f, -100.0f, 235.0f); // Start position of player
	
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SphereMesh; // Sets Mesh

	UPROPERTY(EditAnywhere)
		USphereComponent* Sphere; // Sets Shape
	
		
}
;