// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Cube.generated.h"


UCLASS()
class ATTEMPT1_API ACube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACube();

	UPROPERTY(EditAnywhere) // Means that this component is editable on the Unreal Engine Editor
		UStaticMeshComponent* Mesh; // Mesh for the cube

	UPROPERTY(EditAnywhere)
		UBoxComponent* Cube; // Cube is a box component with built in box physics

	UPROPERTY(EditAnywhere)
		float cubeSpeed = 0.0f; // Speed setter appears on Unreal Engine
	UPROPERTY(EditAnywhere)
		bool movementY = true; // Boolean to get either the cube to move in Y direction or X direction

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float RunningTime;

	
	
};
